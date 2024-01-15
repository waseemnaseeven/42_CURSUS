const express = require('express')
const app = express()
const morgan = require('morgan')

// Array de personnes
let persons = [
  { "id": 1, "name": "Arto Hellas", "number": "040-123456" },
  { "id": 2, "name": "Ada Lovelace", "number": "39-44-5323523" },
  { "id": 3, "name": "Dan Abramov", "number": "12-43-234345" },
  { "id": 4, "name": "Mary Poppendieck", "number": "39-23-6423122" }
]

// Middleware pour afficher les logs dans la console
app.use((req, res, next) => {
  morgan('tiny')(req, res, () => {});
  next();
});

app.get('/api/person', (request, response) => {
  if (persons) {
    response.json(persons)
  } else {
    response.status(404).end()
  }
})

app.get('/api/person/:id', (request, response) => {
  const id = Number(request.params.id)
  const person = persons.find(person => person.id === id)
  if (person) {
    response.json(person)
  } else {
    response.status(404).end()
  }
})

app.get('/api/info', (request, response) => {
  const requestTime = new Date();
  const numberOfEntries = persons.length;

  response.json({
    message: `PhoneBook has info for ${numberOfEntries} entries`,
    time: requestTime,
  });
});

const PORT = 3001
app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`)
})
