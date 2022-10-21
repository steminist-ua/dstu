import React, {useState} from 'react'

const Weather = () => {

    const [myWeather, setMyWeather] = useState()
    const options = {
        method: 'GET',
        headers: {
            'X-RapidAPI-Key': 'bc3528418cmsh5c4b2ae80175c94p1a28bajsn31a99fd351c5',
            'X-RapidAPI-Host': 'weatherbit-v1-mashape.p.rapidapi.com'
        }
    };

    const getWeather = async () =>{
        fetch('https://weatherbit-v1-mashape.p.rapidapi.com/current?lon=34.616667&lat=48.516667&lang=uk', options)
                .then(response => response.json())
                .then(response => setMyWeather(response))
                .catch(err => console.error(err));
        
        console.log("myWeather", myWeather);
    }
    
    

  return (
    <div>
        <h1 onClick={getWeather}>Weather</h1> 

        {
            myWeather?.count>0 ?
                myWeather.data.map( (item,idex) =>
                    <div key={idex}>
                        <h2>{item.city_name}</h2>
                        <h3>{item.temp}</h3>
                        <h3>{item.weather.description}</h3>
                        <img src={"https://www.weatherbit.io/static/img/icons/"+ item.weather.icon +".png"} alt="" />
                    </div>
                )
                : <p></p>
        }

    </div>
  )
}

export default Weather