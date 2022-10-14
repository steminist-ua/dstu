import React, { useState } from 'react'
import './Todo.scss'

const Todo = () => {

const [text, setText] = useState("")
const [tasks, setTasks] = useState([])
let [idTask, setIdTask] = useState(1)

const addTask = () => {
    const newTask = {
        id: idTask,
        content: text
    }

    setTasks([...tasks, newTask])
    setText("")
    setIdTask(++idTask)
    console.log(tasks);
}

const deleteTask = id =>{
    const newTasks = tasks.filter(task =>{ return task.id !== id})
    setTasks(newTasks)
}

const editTask = id =>{
    const newContent = prompt("Please enter your update: ")
    console.log(newContent);
    if(newContent != null && newContent !== ""){
        const newTasks = tasks.map( task => {
            if(task.id === id){
                task.content = newContent
            }
            return task
        })
        setTasks(newTasks)
    }
}

  return (
    <div>
        <h2>Todo List</h2>
        <div className='add'>
            <input className='add__text' type="text" placeholder='Enter your task' value={text} onChange={(e) => setText(e.target.value)} />
            <input className='add__button' type="button" value="Add" 
            onClick={addTask} />
        </div>

        <div className='todo'>
            {
                tasks.length > 0
                ? tasks.map( item => 
                    <div className='todo__item' key={item.id}>
                        <p className='todo__text'>{item.content}</p>
                        <div className='todo__buttons'>
                            <div className='todo__button todo__delete' 
                            onClick={() => deleteTask(item.id)}>💥</div>
                            <div className='todo__button todo__edit' 
                            onClick={() => editTask(item.id)}>📌</div>
                        </div>
                    </div>
                    )
                : <p>🤩 List is empty...</p>
            }
            {/* <div className='todo__item'>
                <p className='todo__text'> {text} </p>
                <div className='todo__buttons'>
                    <div className='todo__button todo__delete'>💥</div>
                    <div className='todo__button todo__edit'>📌</div>
                </div>
            </div>

            <div className='todo__item'>
                <p className='todo__text'>Todo Item 2</p>
                <div className='todo__buttons'>
                    <div className='todo__button todo__delete'>💥</div>
                    <div className='todo__button todo__edit'>📌</div>
                </div>
            </div> */}
        </div>
    </div>
  )
}

export default Todo