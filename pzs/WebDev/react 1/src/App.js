import './App.css';
import Login from './props/Login';
import { BrowserRouter, Routes, Route } from "react-router-dom";
import Hello from './props/Hello';
import Weather from './weather/Weather';
import Sports from './sports/Sports';
import OpenSport from './sports/OpenSport';
import Genre from './fimls/Genre';

function App() {
  return (
    <div className="App App-header">
      
      <BrowserRouter>
        <Routes>
          {/* <Route path='/' element={<Login />}></Route> */}
          <Route path='/' element={<Sports />}></Route>
          {/* <Route path='/' element={<Genre />}></Route> */}
          <Route path='profile' element={<Hello text="Have a nice day!" />}></Route>
          <Route path='weather' element={<Weather />}></Route>
          <Route path='open_sport' element={<OpenSport />}></Route>
        </Routes>
      </BrowserRouter>

      
    </div>
  );
}

export default App;
