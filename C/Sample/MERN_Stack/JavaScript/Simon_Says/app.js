let gameseq=[];
let user=[];
let started=false;
let level=0;
let btns=["yellow","red","purple","green"];
let h2=document.querySelector('h2');
document.addEventListener('keypress',function(){
    if(started==false){
        console.log("Started");
        started=true;
    levelUp();
    }
})
function gameFlash(btn){
        btn.classList.add("flash");
        setTimeout(function(){
            btn.classList.remove("flash")
        },250);
}

function userFlash(btn){
    btn.classList.add("userflash");
    setTimeout(function(){
        btn.classList.remove("userflash")
    },250);
}
function levelUp(){
    user=[];
    level++;
    h2.innerText=`Level ${level}`
    let randIndx=Math.floor(Math.random()*3)
    let randColor=btns[randIndx];
    let randbtn=document.querySelector(`.${randColor}`)
    gameseq.push(randColor);
    console.log(gameseq);
    gameFlash(randbtn);
}
function check(idx){
    if(user[idx]===gameseq[idx]){
        if(user.length===gameseq.length){
            setTimeout(levelUp(),1000);
        }
    }
    else{
        h2.innerHTML=`Game Over! Your score was <b>${level}</b> <br>Press any key to Start`;
        document.querySelector('body').style.backgroundColor="red";
        setTimeout(function(){
            document.querySelector('body').style.backgroundColor="white";
        },150);
        reset();
    }
}
function btnpress(){
    let btn=this;
    userFlash(btn);
    let userColor=btn.getAttribute("id");
    user.push(userColor);
    check(user.length-1);

    
}

let allbtns=document.querySelectorAll(".btn");
for(btn of allbtns){
    btn.addEventListener("click",btnpress);
}
function reset(){
    started=false;
    gameseq=[]
    user=[]
    level=0;
}