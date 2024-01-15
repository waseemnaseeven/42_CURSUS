import React, { useState, useEffect } from 'react';
import personService from './services/Data'

const App = () => {
  const [persons, setPersons] = useState([]);
  const [newName, setNewName] = useState('');
  const [newNumber, setNewNumber] = useState('');

  useEffect(() => {
    // Utilisez Axios pour récupérer les données du serveur
    personService.getAll()
      .then(response => {
        setPersons(response.data);
      })
      .catch(error => {
        console.error('Error fetching data:', error);
      });
  }, []); // Le tableau vide signifie que le hook d'effet ne dépend d'aucune variable, il se comporte comme componentDidMount

  const addPerson = (event) => {
    event.preventDefault();

    // Vérifier si le nom ou le numéro est vide
    if (!newName || !newNumber) {
      alert('Please enter both name and number.');
      return;
    }
    

    // Vérifier si le nom est déjà présent dans le répertoire
    if (persons.some(person => person.name === newName)) {
      alert(`${newName} is already added to the phonebook.`);
    } else {
      const newPerson = { name: newName, number: newNumber }
      personService.create(newPerson)
      .then(response => {
        setPersons([...persons, response.data]);
        setNewName('');
        setNewNumber('');
        console.log(newName, 'has been added')
      })
      .catch(error => {
        console.error('Error adding person:', error);
      })
    }
  };

  const handleUpdate = (id) => {
    const updatedPerson = {
      name: newName,
      number: newNumber
    };
  
    // Appeler la fonction de mise à jour du service
    personService.update(id, updatedPerson)
      .then(response => {
        // Mise à jour de l'état avec les personnes après la modification
        setPersons(persons.map(person => (person.id === id ? response.data : person)));
        setNewName('');
        setNewNumber('');
        console.log(newName, 'has been updated');
      })
      .catch(error => {
        console.error('Error updating person:', error);
      });
  };

  const handleErase = (id) => {
    personService.erase(id)
    .then(response => {
      setPersons(persons.filter(person => person.id !== id))
      console.log(persons.newName, 'has been deleted')
    })
    .catch(error => {
      console.error('Error erasing person: ', error)
    })
  }

  const handleNameChange = (event) => {
    setNewName(event.target.value);
  };

  const handleNumberChange = (event) => {
    setNewNumber(event.target.value);
  };

  return (
    <div>
      <h2>Phonebook</h2>
      <form onSubmit={addPerson}>
        <div>
          name: <input value={newName} onChange={handleNameChange} />
        </div>
        <div>
          number: <input value={newNumber} onChange={handleNumberChange} />
        </div>
        <div>
          <button type="submit">add</button>
        </div>
      </form>
      <h2>Numbers</h2>
      {persons.map((person, index) => (
        <div key={index}>{person.name} - {person.number}
        <button type="button" onClick={() => handleErase(person.id)}>delete</button>
        </div>
      ))}
    </div>
  );
};

export default App;
