import React, {useState, useEffect} from 'react'
import { Link, useLocation } from "react-router-dom";

const OpenSport = () => {

    const location = useLocation();
    const name = location.state?.data;

    const [sports, setSports] = useState([]);
    useEffect(() => {
        loadSports();
    },[]);

    const loadSports = async () => {
        const options = {
            method: 'GET',
            headers: {
                'X-RapidAPI-Key': 'bc3528418cmsh5c4b2ae80175c94p1a28bajsn31a99fd351c5',
                'X-RapidAPI-Host': 'odds.p.rapidapi.com'
            }
        };
        
        fetch('https://odds.p.rapidapi.com/v4/sports/'+name+'/scores?daysFrom=3', options)
            .then(response => response.json())
            .then(response => setSports(response))
            .then(response => console.log(sports))
            .catch(err => console.error(err));
    }

  return (
    <div>
        <h2>Games ✨ <Link to="/">Back</Link></h2>
        <table className='games'>
            {sports?.length>0 ?
                sports.map (item => 
                    <tr key={item.id}>
                        <td>{item.sport_title}</td>
                        <td>{ new Date(item.commence_time).toLocaleDateString() }</td>
                        <td>{item.completed?"✅":"📅"}</td>
                        <td>   
                            {item.home_team} : { item.away_team}
                            <br/> { item.scores?.length>0? item.scores[0].score : ''} : { item.scores?.length>0? item.scores[1].score : ''}
                        </td>
                    </tr>
                )
                :<tr><td>Sports is empty... </td></tr>
            }
        </table>
    </div>
  )
}

export default OpenSport