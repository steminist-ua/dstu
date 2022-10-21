import React, {useState} from 'react'
import './Login.scss'

import { Link } from "react-router-dom";

const Login = () => {

    const [name, setName] = useState("")

  return (
    <div>
        <h2>Log In</h2>
        <div className='login'>
            <input className='login__name' type="text" placeholder='Enter your name...' value={name} onChange={(e) => setName(e.target.value)} />
            <Link className='login__button' to='/profile' state={{ data: name}}>Done</Link>
        </div>
    </div>
  )
}

export default Login