trait Person {
    fn name(&self) -> String;
}

// Student is a supertrait of Person.
// Implementing Student requires you to also impl Person.
trait Student: Person{
    fn university(&self) -> String;
}

trait Programmer {
    fn fav_language(&self) -> String;
}

// CompSciStudent (computer science student) is a supertrait of both Programmer 
// and Student. Implementing CompSciStudent requires you to impl both subtraits.
trait CompSciStudent: Programmer + Student {
    fn git_username(&self) -> String;
}

fn _comp_sci_student_greeting(student: &dyn CompSciStudent) -> String {
    format!(
        "My name is {} and I attend {}. My Git username is {}",
        student.name(),
        student.university(),
        student.git_username()
    )
}

#[derive(Debug)]
struct Stu {
    name: String,
    university: String,
    git_username: String,
}

impl Person for Stu {
    fn name(&self) -> String { "Yam".to_string() }
}

impl Student for Stu {
    fn university(&self) -> String { "XJTU".to_string() }
}

impl Programmer for Stu {
    fn fav_language(&self) -> String { "Rust".to_string() }
}

impl CompSciStudent for Stu {
    fn git_username(&self) -> String { "hscspring".to_string() }
}


fn main() {
    let stu = Stu {
        name: String::from("USER"),
        university: String::from("UNIVER"),
        git_username: String::from("GIT")
    };
    let greet: String = _comp_sci_student_greeting(&stu);
    println!("{:?}", stu);
    println!("{:?}", greet);
}

