let btn=document.querySelector("#btnadd");
let inpu=document.querySelector("input");
function change(){
    let ul=document.createElement("ul");
    let li=document.createElement("li");
    document.querySelector(".tasks").append(ul);
    document.querySelector("ul").append(li);
    li.innerHTML=`${inpu.value}<button class="btn btn-danger" id="#btndelete"><i class="fa-solid fa-trash"></i></button>`
    li.classList.add("todo");
    let del=document.querySelectorAll(".tasks ul li .btn");
    for(ele of del){
        ele.addEventListener('click',function(){
            let par=this.parentElement;
            par.remove();   
            document.querySelector(".bottom p").innerHTML=`<p>You have ${document.querySelectorAll("ul li").length} pending tasks</p>`;
        })
    } 
    document.querySelector(".bottom p").innerHTML=`<p>You have ${document.querySelectorAll("ul li").length} pending tasks</p>`;
}

btn.addEventListener('click',change);

let clearall_btn=document.querySelector("#clearall");
    clearall_btn.addEventListener('click',function(){
        document.querySelector(".tasks ul").remove();
        document.querySelector(".bottom p").innerHTML=`<p>You have 0 pending tasks</p>`;
    
    })
    
    





