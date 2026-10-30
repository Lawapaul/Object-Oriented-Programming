let arr=["My","Name","is","Harshit","Singh","Shekhawat","."];
let str="";
function concatenate(arr,str){
    for(let i=0;i<arr.length;i++){
        str+=arr[i];
        str+=" ";
        
    }
    console.log(str);
}
concatenate(arr,str);