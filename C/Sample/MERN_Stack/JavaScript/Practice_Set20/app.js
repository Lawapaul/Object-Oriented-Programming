let para=document.createElement('p');
document.querySelector('body').append(para);
para.innerText="Hey, I am Red";
para.style.color="red";

let h3=document.createElement('h3');
document.querySelector('body').append(h3);
h3.innerText="Hey, I am Blue";
h3.style.color="Blue";

let div=document.createElement('div');
document.querySelector('body').append(div);
div.classList.add("box");

let h1=document.createElement('h1');
let p=document.createElement('p');
document.querySelector('.box').append(h1);
document.querySelector('.box').append(p);
h1.innerText="I'm in a Div";
p.innerText="Me, Too";

