import React, {useState, useEffect} from 'react'
import { Link } from "react-router-dom";

const Genre = () => {

    const [sports, setSports] = useState([]);

    useEffect(() => {
        loadSports();
    },[]);

    const loadSports = async() => {
        const options = {
            method: 'GET',
        };
        
        fetch('https://localhost:44386/api/Genre/', options)
            .then(response => response.json())
            .then(response => console.log(response))
            .catch(err => console.error(err));
    }

  return (
    <div>Genre</div>
  )
}

export default Genre