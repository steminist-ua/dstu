# CSS Селектори та Псевдокласи — Повний гайд з прикладами

> Цей конспект — **практичний полігон**: для кожного типу селекторів є коротке пояснення та **живі приклади** (`HTML + CSS`) в одному блоці. Копіюй у свій редактор і запускай.

---

## Зміст
1. [Базові селектори](#базові-селектори)
2. [Комбінатори](#комбінатори)
3. [Атрибутні селектори](#атрибутні-селектори)
4. [Псевдокласи: взаємодія та навігація](#псевдокласи-взаємодія-та-навігація)
5. [Псевдокласи: структура документа](#псевдокласи-структура-документа)
6. [Псевдокласи: мова та напрям](#псевдокласи-мова-та-напрям)
7. [Псевдокласи: форми та валідація](#псевдокласи-форми-та-валідація)
8. [Псевдокласи: логічні та композиційні](#псевдокласи-логічні-та-композиційні)
9. [Псевдокласи: колонки таблиць](#псевдокласи-колонки-таблиць)
10. [Shadow DOM (Web Components): спеціальні псевдокласи](#shadow-dom-web-components-спеціальні-псевдокласи)
11. [Псевдоелементи (бонус)](#псевдоелементи-бонус)
12. [Специфічність і поради](#специфічність-і-поради)
13. [Міні‑челенджі для практики](#мінічеленджі-для-практики)

---

## Базові селектори

### 1) Селектор типу (Type)
Вибирає елементи за назвою тега.
```html
<h2>Заголовок</h2><p>Текст</p>
<style>
h2 { color: teal; }
p  { line-height: 1.6; }
</style>
```

### 2) Селектор класу (Class)
```html
<div class="card">Hello</div>
<style>
.card { border: 1px solid #ccc; padding: 1rem; border-radius: 12px; }
</style>
```

### 3) Селектор ідентифікатора (ID)
```html
<div id="hero">Hero</div>
<style>
#hero { background: #222; color:#fff; padding:1rem; }
</style>
```

### 4) Універсальний (`*`)
```html
<ul class="menu"><li>Home</li><li>About</li></ul>
<style>
.menu * { font-family: system-ui; }
</style>
```

### 5) Групування селекторів (`,`)
```html
<h1>Група</h1><h2>Група</h2><p class="lead">Група</p>
<style>
h1, h2, .lead { margin-bottom: .5rem; }
</style>
```

---

## Комбінатори

### 1) Нащадок (пробіл): `A B`
Будь‑який рівень вкладеності.
```html
<article class="post"><p><a href="#">посилання</a></p></article>
<style>
.post a { color: tomato; }
</style>
```

### 2) Дитина (`A > B`) — лише прямий рівень
```html
<ul class="nav"><li><a>…</a></li></ul>
<style>
.nav > li { list-style: "👉 "; }
</style>
```

### 3) Суміжний сусід (`A + B`) — **перший** після
```html
<h3>Заголовок</h3><p>Перший</p><p>Другий</p>
<style>
h3 + p { font-weight: 600; }
</style>
```

### 4) Будь‑які наступні сусіди (`A ~ B`)
```html
<label>Опції</label><p>А</p><p>Б</p>
<style>
label ~ p { color: #555; }
</style>
```

### 5) Колонковий комбінатор (`A || B`) — для таблиць/колонок
```html
<table>
  <colgroup><col class="money"><col><col class="money"></colgroup>
  <tr><th>Назва</th><th>К-ть</th><th>Сума</th></tr>
  <tr><td>Кава</td><td>2</td><td>180</td></tr>
</table>
<style>
.money || td { text-align: right; font-variant-numeric: tabular-nums; }
</style>
```

---

## Атрибутні селектори

### 1) Точне співпадіння
```html
<a href="/" target="_blank">Відкрити</a>
<style>
a[target="_blank"] { text-decoration: underline dotted; }
</style>
```

### 2) Префікс/суфікс/підрядок
```html
<a href="/guide.PDF">PDF</a>
<img src="https://picsum.photos/80">
<a href="/go/example-route">example</a>
<style>
img[src^="https://"] { outline: 2px solid #0a0; }  /* починається з */
a[href$=".pdf" i]    { color: firebrick; }         /* закінчується на (i — без регістру) */
a[href*="example"]   { color: royalblue; }         /* містить */
</style>
```

### 3) Спискові/словникові значення
```html
<p class="btn primary">Кнопка</p>
<style>
[class~="btn"] { padding:.5rem 1rem; }      /* слово в пробіл-розділеному списку */
html[lang|="uk"] { quotes: "«" "»" "„" "“"; } /* uk або uk-UA */
</style>
```

### 4) Флаги чутливості до регістру: `i` / `s`
```html
<a href="/FILE.PDF">PDF</a>
<style>
a[href$=".pdf" i] { color: crimson; } /* pdf/PDF/PdF */
</style>
```

---

## Псевдокласи: взаємодія та навігація

### 1) `:hover`, `:active`, `:focus`, `:focus-visible`, `:focus-within`
```html
<label class="field">
  <span>Пошта</span>
  <input type="email" placeholder="you@example.com">
</label>
<style>
.field { border:1px solid #ccc; padding:.5rem; display:inline-grid; gap:.4rem; }
.field:focus-within { border-color: dodgerblue; box-shadow: 0 0 0 3px #1e90ff33; }
input:focus-visible { outline: 2px solid cornflowerblue; }
button:hover { filter: brightness(1.05); }
button:active { transform: translateY(1px); }
</style>
```

### 2) Посилання: `:any-link`, `:link`, `:visited`
```html
<a href="#x">Локальне</a> · <a href="https://example.com">Зовнішнє</a>
<style>
:any-link { color: #06c; }
:visited  { color: purple; } /* для відвіданих URL */
</style>
```

### 3) Якір сторінки: `:target`
```html
<a href="#faq1">FAQ 1</a> • <a href="#faq2">FAQ 2</a>
<section id="faq1">Відповідь 1</section>
<section id="faq2">Відповідь 2</section>
<style>
:target { outline: 2px dashed orange; scroll-margin-top: 2rem; }
</style>
```

### 4) Повноекранний режим та модальні: `:fullscreen`, `:modal`, `:popover-open`
```html
<dialog id="d">Привіт</dialog>
<style>
:modal { border: 2px solid #333; border-radius: 8px; }
:popover-open { outline: 2px solid #999; } /* для елементів у Popover API */
</style>
```

> Примітка: підтримка `:popover-open` залежить від браузера.

---

## Псевдокласи: структура документа

### 1) Базові структурні
- `:root` — корінь документа (`html`).
- `:empty` — вузол без дітей/тексту.
- `:first-child` / `:last-child` / `:only-child`.

```html
<ul class="notes">
  <li>А</li>
  <li></li>
  <li>В</li>
</ul>
<style>
:root { --gap: .5rem; }
.notes li:first-child { font-weight:700; }
.notes li:last-child  { color: teal; }
.notes li:only-child  { color: red; }
.notes li:empty { min-height: 1em; background: #fffa; }
</style>
```

### 2) За типом тега (of-type)
- `:first-of-type` / `:last-of-type` / `:only-of-type`
- `:nth-of-type()` / `:nth-last-of-type()`

```html
<article>
  <h2>H2 #1</h2><p>p #1</p>
  <h2>H2 #2</h2><p>p #2</p>
</article>
<style>
article p:first-of-type { font-style: italic; }
article h2:last-of-type { text-decoration: underline; }
</style>
```

### 3) `:nth-child(An+B)` та друзі
- `odd` / `even`
- `An+B` (напр. `3n+1`)
- `:nth-last-child()` — з кінця
- **Фільтрація підмножини:** `:nth-child(An+B of S)`

```html
<ul class="grid">
  <li>1</li><li>2</li><li>3</li><li>4</li><li>5</li><li>6</li>
</ul>
<ul class="people">
  <li class="vip">Ann</li>
  <li>Bob</li>
  <li class="vip">Cody</li>
  <li class="vip">Dora</li>
  <li>Eva</li>
</ul>
<style>
.grid { display:grid; grid-template-columns: repeat(3, 3rem); gap:.5rem; }
.grid li:nth-child(odd)  { background:#eef; }
.grid li:nth-child(3n+1) { border: 1px solid #99c; }

/* кожен другий серед лише .vip */
.people li:nth-child(2n of .vip) { background: #ffe8a3; }
</style>
```

### 4) `:scope`
Позначає «поточний корінь» (корисно з JS/вкладеними селекторами).
```html
<div class="card">
  <header><h3>Заголовок</h3></header>
  <p>Текст</p>
</div>
<style>
.card:has(:scope > header h3) { border-left: 4px solid seagreen; }
</style>
```

---

## Псевдокласи: мова та напрям

### 1) `:lang()`
```html
<p lang="uk">Привіт!</p>
<p lang="en">Hello!</p>
<style>
p:lang(uk) { font-style: italic; }
</style>
```

### 2) `:dir(ltr|rtl)`
```html
<p dir="rtl">مرحبا</p>
<style>
p:dir(rtl) { text-align: right; }
</style>
```

---

## Псевдокласи: форми та валідація

### 1) Доступність і редагованість
- `:enabled` / `:disabled`
- `:read-write` / `:read-only`

```html
<input value="read-only" readonly>
<input value="can edit">
<style>
input:read-only { background:#f5f5f5; }
input:read-write { background:#fff; }
</style>
```

### 2) Обов’язковість і правильність
- `:required` / `:optional`
- `:valid` / `:invalid`
- `:user-valid` / `:user-invalid` (стан користувача)
- `:in-range` / `:out-of-range`

```html
<form class="f">
  <input type="email" required placeholder="you@example.com">
  <input type="number" min="1" max="5" value="7">
  <button>OK</button>
</form>
<style>
.f input:required:invalid { border:2px solid #e33; }
.f input:in-range         { box-shadow: 0 0 0 2px #0c04 inset; }
.f input:out-of-range     { box-shadow: 0 0 0 2px #e33 inset; }
.f input:user-valid       { border-color: #0a4; }
</style>
```

### 3) Вибірники стану елементів форм
- `:checked` / `:indeterminate` / `:default`
- `:placeholder-shown`
- `:autofill` *(підтримка залежить від браузера)*

```html
<label><input type="checkbox" checked> Згоден</label>
<input placeholder="placeholder...">
<style>
input:placeholder-shown{ background:#fafafa; }
input:autofill { outline: 2px dashed gold; } /* підтримка різна */
</style>
```

---

## Псевдокласи: логічні та композиційні

### 1) `:not()` — виключення
```html
<button class="btn">OK</button>
<button class="btn secondary">Cancel</button>
<style>
button:not(.secondary) { background:#111; color:#fff; }
</style>
```

### 2) `:is()` — «список АБО», бере **найвищу** специфічність серед аргументів
```html
<article class="prose">
  <h1>Заголовок</h1><h2>Підзаголовок</h2><p>Текст</p>
</article>
<style>
.prose :is(h1, h2) { letter-spacing: .02em; }
</style>
```

### 3) `:where()` — як `:is()`, але специфічність = **0**
```html
<article class="prose">
  <h1>Заголовок</h1><h2>Підзаголовок</h2><p>Текст</p>
</article>
<style>
:where(.prose) :where(h1, h2, h3, p) { margin: .6em 0; }
</style>
```

### 4) `:has()` — **батьківський селектор**
```html
<article class="card">
  <header><h3>Новина</h3></header>
  <p>Текст</p>
</article>
<article class="card"><p>Без заголовка</p></article>
<style>
.card:has(> header h3) { border-left: 4px solid mediumseagreen; }

/* Приклад: показати кнопку «Очистити», якщо поле вводу непорожнє */
.search .clear{ opacity:.25; pointer-events:none; }
.search:has(input:not(:placeholder-shown)) .clear{ opacity:1; pointer-events:auto; }
</style>
```

---

## Псевдокласи: колонки таблиць

- `:nth-col()` / `:nth-last-col()` — індексація **колонок** (на відміну від рядків)
```html
<table>
  <colgroup><col><col><col></colgroup>
  <tr><th>Назва</th><th>К-ть</th><th>Ціна</th></tr>
  <tr><td>Ноутбук</td><td>2</td><td>4800</td></tr>
  <tr><td>Миша</td><td>3</td><td>60</td></tr>
</table>
<style>
:root :nth-col(n+2) { background: #f7faff; } /* 2-а і далі */
</style>
```

---

## Shadow DOM (Web Components): спеціальні псевдокласи

> Для веб‑компонентів у **Shadow DOM** доступні додаткові псевдокласи.

- `:host` / `:host(selector)` — стилізує кореневий хост-компонент
- `:host-context(selector)` — якщо предок у світлій DOM відповідає селектору
- `:defined` — елемент є **визначеним** (custom element зареєстровано)

```html
<!-- Припустімо, є <my-card> з Shadow DOM -->
<my-card class="warning"></my-card>

<style>
/* всередині shadow CSS: */
:host { display:block; border:1px solid #ddd; padding:1rem; }
:host(.warning) { border-color: orange; }
:host-context(body.dark) { background:#111; color:#eee; }
:defined { outline: 1px dashed #999; } /* можна ззовні для custom elements */
</style>
```

---

## Псевдоелементи (бонус)

Хоч це **не псевдокласи**, часто йдуть разом у практиці:

- `::before` / `::after` — декоративний контент
- `::first-line`, `::first-letter`
- `::selection`
- `::marker` (маркери списків)
- `::placeholder`
- `::file-selector-button`
- `::backdrop` (для `<dialog>` у `:modal`)
- `::part()` / `::slotted()` — для Shadow DOM

```html
<ul class="todo">
  <li>Купити каву</li>
  <li class="done">Написати звіт</li>
</ul>
<style>
.todo li::marker { content: "• "; color: #888; }
.todo li.done::before { content: "✅ "; }
::selection { background: #fffa9e; }
</style>
```

---

## Специфічність і поради

- **Ієрархія:** `ID` > `Class/attr/pseudo-class` > `Type` > `*`  
  - `#id` → **1‑0‑0**  
  - `.btn:hover` → **0‑2‑0**  
  - `article h2` → **0‑0‑2**
- `:is()` — бере **найвищу** специфічність аргументів; `:where()` — **0**.
- Вживай `:where()` для **утилітарних** низькоспецифічних стилів, щоб їх легко перевизначати.
- Використовуй `:has()` для **реактивних** батьківських станів без JS (напр., показ/приховування елементів залежно від вмісту).
- Атрибутні селектори з флагом `i` — зручно при різних регістрах (PDF/pdf).

---

## Міні‑челенджі для практики

1. **Зебра‑таблиця:** підсвіти парні рядки, а колонки 2–3 — іншим фоном за допомогою `:nth-child()` і `:nth-col()`; числа вирівняй праворуч через комбінатор `||`.\
2. **Форма з валідацією:** показуй підказку лише при `:user-invalid`, але рамку — при `:invalid`. Додай `:focus-visible` для доступності.\
3. **Меню без JS:** підсвічуй активний пункт меню через `:target`, а стан вкладеного меню — через `:has()` у батьківському контейнері.\
4. **Картки блогу:** виділяй `.card:has(img)` тінню; `.card:not(:has(img))` — сірою рамкою; додай `:lang()` для локалізованих цитат.\
5. **Компонент з Shadow DOM:** стилізуй `:host(.warning)` і варіант для темної теми через `:host-context(body.dark)`.

---

> 📌 **Підсумок:** у сучасному CSS особливо зверни увагу на **`:has`**, **`:is`/`:where`**, **`:focus-visible`**, **`:nth-child(... of S)`** і колонкові селектори — вони кардинально спрощують логіку без JavaScript.
