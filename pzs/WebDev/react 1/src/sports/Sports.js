import React, {useState, useEffect} from 'react'
import { Link } from "react-router-dom";
import './Sports.scss'

const Sports = () => {

    const [sports, setSports] = useState([]);

    useEffect(() => {
        loadSports();
    },[]);

    const loadSports = async() => {
        const options = {
            method: 'GET',
            headers: {
                'X-RapidAPI-Key': 'bc3528418cmsh5c4b2ae80175c94p1a28bajsn31a99fd351c5',
                'X-RapidAPI-Host': 'odds.p.rapidapi.com'
            }
        };
        
        fetch('https://odds.p.rapidapi.com/v4/sports?all=true', options)
            .then(response => response.json())
            .then(response => setSports(response))
            .catch(err => console.error(err));
    }

  return (
    <div>
        <h1>Sports</h1>
        <div className='sports'>
            {
                sports?.length>0 ?
                sports.map (item => 
                    <div key={item.key} className='sports__item'>
                        <h3><Link to="/open_sport" state={{ data: item.key }}> {item.title}</Link></h3>
                        <p><i>{item.description}</i></p>
                        <p>Group: {item.group}</p>
                    </div>
                )
                :<p>Sports is empty...</p>
            }
        </div>
    </div>
  )
}

export default Sports