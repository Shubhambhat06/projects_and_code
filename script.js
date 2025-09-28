function person(name , surname , age , gender){
    this.name = name
    this.surname = surname
    this.age = age
    this.gender = gender
}
person.prototype.name = function (){
    console.log(this.name + this.surname)
}
let q = new person("shubham" , "bhat" , 20 , "male")
q.name()
