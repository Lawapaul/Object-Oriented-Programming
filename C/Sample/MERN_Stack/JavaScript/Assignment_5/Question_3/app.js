let arr=["Australia","Germany","United States of America"];

function max(){
    let ini=arr[0].length;
    let maxi=0;
    for(let i=0;i<arr.length;i++){
        let check=arr[i].length;
        if(check>ini){
            ini=arr[i].length;
            maxi=i;
        }
        else{
            continue;
        }
    }
    console.log(arr[maxi]);
}
max();