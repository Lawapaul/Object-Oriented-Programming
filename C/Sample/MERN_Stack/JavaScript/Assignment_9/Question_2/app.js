let inpu=document.createElement('input');
inpu.placeholder="Enter Your Name";
document.querySelector('body').append(inpu);

let h2=document.createElement('h2');
h2.innerText="Your name here";
document.querySelector('body').prepend(h2);

function change(){
    h2.innerText=inpu.value;
    inpu.addEventListener('keydown',function (event){
        if(event.code=='60'){
           
        }
    })
    
}
inpu.addEventListener('keydown',change);
