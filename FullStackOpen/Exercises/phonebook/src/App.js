import React, { useState, useEffect } from 'react';
import axios from 'axios';

const App = () => {
  const [persons, setPersons] = useState([]);
  const [newName, setNewName] = useState('');
  const [newNumber, setNewNumber] = useState('');

  useEffect(() => {
    // Utilisez Axios pour récupérer les données du serveur
    axios.get('http://localhost:3001/persons')
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
      axios.post('http://localhost:3001/persons', { name: newName, number: newNumber })
      .then(response => {
        setPersons([...persons, response.data]);
        setNewName('');
        setNewNumber('');
      })
      .catch(error => {
        console.error('Error adding person:', error);
      })
    }
  };

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
        <div key={index}>{person.name} - {person.number}</div>
      ))}
    </div>
  );
};

export default App;
