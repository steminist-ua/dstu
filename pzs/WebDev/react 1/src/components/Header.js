import React, {useState} from 'react'
import './Header.css'

export const Header = () => {

    // let a = 5
    let [a, setA] = useState(0)
    let array =["Header", "React", "useState"]

    let array2 = [
        {id: 100, name: "Name 1"},
        {id: 102, name: "Name 2"},
        {id: 103, name: "Name 3"}
    ]

    const changeA = () => {
        // a++
        setA(++a)
        console.log(a);
    }

    const handleChange = event => {
        console.log(event.target.value);
        setA(event.target.value)
    }

    return (
        <div>
            <h1 className='text'>App header</h1>
            <p>
                {/* lorem {20 + 575} */}
                lorem {a}
            </p>
            <p className={ a%2 ? 'text-red' : 'text-yellow'}>
                lorem 2
            </p>
            <button onClick={changeA}>Change A</button>

            <ol>
                {
                    array.length > 0
                        ? array.map(item => <li>{item}</li>)
                        : <li>Array is empty</li>
                }
            </ol>


            <table>
            {
                array2.length > 0
                    ? array2.map (item =>
                        <tr>
                            <td>{item.id}</td>
                            <td>{item.name}</td>
                        </tr>
                     )
                    : <tr> <td>Array is empty</td> </tr>
            }
            </table>

            <input type="number" value={a} onChange={handleChange}></input>
            
        </div>
    )
}
