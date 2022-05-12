# Лабораторна робота №6
## Фреймворк Bootstrap

Офіційний сайт https://getbootstrap.com/

- документація Bootstrap - https://getbootstrap.com/docs/5.1/getting-started/introduction/
- підключення до html сторінки 

    ```html
    <!-- CSS only -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">

    <!-- JavaScript Bundle with Popper -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    ``` 
- Bootstrap Icons - https://icons.getbootstrap.com/

    підключення у html
    ```html 
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.8.1/font/bootstrap-icons.css">
    ```
    або у css
    ```css
    @import url("https://cdn.jsdelivr.net/npm/bootstrap-icons@1.8.1/font/bootstrap-icons.css");
    ```

- Animate.css - https://animate.style/
    ```html
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/animate.css/4.1.1/animate.min.css" />
    ```
    приклад використання на сторінці
    ```html
    <!-- animate__animated - обов'язково, далі через пробіл назва анімації, наприклад - animate__bounce -->
    <h1 class="animate__animated animate__bounce">An animated element</h1>
    ```
- ознайомитися з методологією БЕМ (https://ru.bem.info/methodology/)
- створити сторінку відповідно до макета: 
    - посилання на макет у figma: [відкрити макет](https://www.figma.com/file/qik5vVTBNLtVXKEGXJFvPE/agency?node-id=1483%3A2) (*рекомендую встановити figma*, тоді буде доступне копіювання зображень та текстів, значення кольорів, розміри тощо. *у браузерній версії доступний тільки перегляд*)
- верстати макет за принципом mobile-first - спочатку для екранів мобільних 
- додати анімацію за допомогою бібліотеки `Animate.css`
