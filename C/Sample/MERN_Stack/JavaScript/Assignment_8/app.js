let btn=document.createElement('button')
let inpu=document.createElement('input');
btn.innerText="Click Me";
document.querySelector("body").append(btn);
document.querySelector("body").append(inpu);

///Ans 2
inpu.setAttribute('placeholder','username');
btn.id="btn";
let select=document.querySelector("#btn");

///Ans 3
select.style.backgroundColor="blue";
select.style.color="White";

///Ans 4
let heading=document.createElement("h1");
document.querySelector('body').prepend(heading)
heading.innerText="Dom Practice";

///Ans 5
let para=document.createElement('p');
document.querySelector('body').append(para);
para.innerHTML="Apna College <b>Delta</b> Practice";