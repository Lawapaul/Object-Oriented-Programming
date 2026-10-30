let h1=document.createElement("h1");
h1.innerText="Generate a Random Number";
document.querySelector('body').append(h1);
h1.classList.add('heading');

let btn=document.createElement('button');
btn.innerText="Generate Color";
document.querySelector('body').append(btn);
btn.classList.add('btn');

let div=document.createElement('div');
div.innerText="This is your new Color";
document.querySelector('body').append(div);
div.classList.add('box');

function color(){
    let num1=Math.floor(Math.random()*255)
    let num2=Math.floor(Math.random()*255)
    let num3=Math.floor(Math.random()*255)
    div.style.backgroundColor=`rgb(${num1},${num2},${num3})`;
    h1.innerText=`rgb(${num1},${num2},${num3})`;
}
btn.addEventListener('click',color);