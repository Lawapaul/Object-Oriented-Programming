let btn=document.createElement('button');
btn.innerText="Click Me";
document.querySelector('body').append(btn);

let change=function(){
    this.style.backgroundColor='green';
}
btn.addEventListener('click',change);