import React from 'react'
import { Link, useLocation } from "react-router-dom";

const Hello = (props) => {

    const location = useLocation();

    console.log(props, " props");
    console.log(location, " useLocation Hook");

    const name = location.state?.data;

  return (
    <div>
        <h2>Hello {name} 🤩 <i>{props.text}</i> </h2>
        <Link className='login__button' to="/">Back</Link>
    </div>
  )
}

export default Hello