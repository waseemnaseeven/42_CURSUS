// import React, { useState } from 'react';

// const Button = ({ handleClick, text }) => (
//   <button onClick={handleClick}>{text}</button>
// );

// const Statistiques = ({ good, neutral, bad }) => {
//   const total = good + neutral + bad;
//   const average = total / 3;
//   const positive = (good / total) * 100;

//   return (
//     <div>
//       <h1>Statistics</h1>
//       <table>
//         <tbody>
//           <tr>
//             <td>Good</td>
//             <td>{good}</td>
//           </tr>
//           <tr>
//             <td>Neutral</td>
//             <td>{neutral}</td>
//           </tr>
//           <tr>
//             <td>Bad</td>
//             <td>{bad}</td>
//           </tr>
//           <tr>
//             <td>Total</td>
//             <td>{total}</td>
//           </tr>
//           <tr>
//             <td>Average</td>
//             <td>{average}</td>
//           </tr>
//           <tr>
//             <td>Positive</td>
//             <td>{positive} %</td>
//           </tr>
//         </tbody>
//       </table>
//     </div>
//   );
// };


// const App = () => {
//   const [good, setGood] = useState(0);
//   const [neutral, setNeutral] = useState(0);
//   const [bad, setBad] = useState(0);

//   const handleGoodClick = () => {
//     setGood(good + 1);
//   };

//   const handleNeutralClick = () => {
//     setNeutral(neutral + 1);
//   };

//   const handleBadClick = () => {
//     setBad(bad + 1);
//   };

//   return (
//     <div>
//       <h1>give feedback</h1>
//       <Button handleClick={handleGoodClick} text="good" />
//       <Button handleClick={handleNeutralClick} text="neutral" />
//       <Button handleClick={handleBadClick} text="bad" />
//       <Statistiques good={good} neutral={neutral} bad={bad} />
//     </div>
//   );
// };

// export default App;

import { useState } from 'react'

const Button = ({ handleClick, text }) => (
  <button onClick={handleClick}>{text}</button>
);

const App = () => {
  const anecdotes = [
    'If it hurts, do it more often.',
    'Adding manpower to a late software project makes it later!',
    'The first 90 percent of the code accounts for the first 10 percent of the development time...The remaining 10 percent of the code accounts for the other 90 percent of the development time.',
    'Any fool can write code that a computer can understand. Good programmers write code that humans can understand.',
    'Premature optimization is the root of all evil.',
    'Debugging is twice as hard as writing the code in the first place. Therefore, if you write the code as cleverly as possible, you are, by definition, not smart enough to debug it.',
    'Programming without an extremely heavy use of console.log is same as if a doctor would refuse to use x-rays or blood tests when diagnosing patients.'
  ]
   
  const [selected, setSelected] = useState(0)


  const nextAnecdotes = () => {
    const randomIndex = Math.floor(Math.random() * anecdotes.length);
    setSelected(randomIndex)
  }

  return (
    <div>
      <p>{anecdotes[selected]}</p>
      <Button handleClick={nextAnecdotes} text="next anecdotes" />
    </div>
  )
}

export default App