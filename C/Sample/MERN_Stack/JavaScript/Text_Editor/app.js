let text=document.querySelector('textarea');
let h2=document.querySelector('h2');
function change(){
    h2.innerText=text.value;
}
text.addEventListener('input',change);