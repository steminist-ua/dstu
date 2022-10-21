import './App.css';
import Login from './props/Login';
import { BrowserRouter, Routes, Route } from "react-router-dom";
import Hello from './props/Hello';

function App() {
  return (
    <div className="App App-header">
      
      <BrowserRouter>
        <Routes>
          <Route path='/' element={<Login />}></Route>
          <Route path='profile' element={<Hello text="Have a nice day!" />}></Route>
        </Routes>
      </BrowserRouter>

      
    </div>
  );
}

export default App;
