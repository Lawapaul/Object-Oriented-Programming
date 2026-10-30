list=["eat","sleep","code"];
while(true){
    console.log("1. List\n2. Add\n3. Delete\n4. Quit\nChoice: ");
    let input=prompt("Enter Choice");
    if(input==1){
        for(let i=0;i<list.length;i++){
            console.log(`List:\n${i+1}: `,list[i])
        }
    }
    else if(input==2){
            let inpu=prompt("Enter a todo: ");
            list.push(inpu);
        
    }
    else if(input==3){
        let del=prompt("Enter item to delete");
        for(let i=0;i<list.length;i++){
            if(del==list[i]){
                list.splice(i,1);
            }
        }
    }
    else{
        console.log("Thankyou!");
        break;
    }
    let con=prompt("Do you wish to Continue (Y/N)?");
    if((con=="n") || (con=="N")){
        break;
    }
    else{
        continue;
    }

}
