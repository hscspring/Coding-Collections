fn main() {

    let optional = Some(7);
    match optional {
        Some(i) => {
            println!("This is a really long string and `{:?}`", i);
            // ^ Needed 2 indentations just so we could destructure
            // `i` from the option.
        },
        _ => {},
        // ^ Required because `match` is exhaustive. Doesn't it seem
        // like wasted space?
    }


    let number = Some(7);
    let letter: Option<i32> = None;
    let emoticon: Option<i32> = None;

    // The `if let` construct reads: "if `let` destructures `number` into
    // `Some(i)`, evaluate the block (`{}`).

    if let Some(i) = number {
        println!("Matched {:?}", i);
    }

    // If you need to specify a failure, use an else
    if let Some(i) = letter {
        println!("Matched {:?}", i);
    } else {
        // Destructure failed 
        println!("Didn't match a number. Let's go with a letter!");
    }

    // Provide an altered failing condition.
    let i_like_letters = false;

    if let Some(i) = emoticon {
        println!("Matched {:?}!", i);
    // Destructure failed. Evaluate an `else if` condition to see if the
    // alternate failure branch should be taken:
    } else if i_like_letters {
        println!("Didn't match a number. Let's go with a letter!");
    } else {
        // The condition evaluated false. This branch is the default:
        println!("I don't like letters. Let's go with an emoticon :)!");
    }




    // Our example enum
    enum Foo {
        Bar,
        Baz,
        Qux(u32)
    }

    // Create example variables
    let a = Foo::Bar;
    let b = Foo::Baz;
    let c = Foo::Qux(100);

    // Variable b does not match Foo::Bar
    if let Foo::Bar = b {
        println!("b is foobar");
    }

    // Variable c matches Foo:Qux 
    if let Foo::Qux(value) = c {
        println!("c is {}", value);
    }

    // Binding also works
    if let Foo::Qux(value @ 100) = c {
        println!("c is one hundred");
    }



    // This enum purposely doesn't #[derive(PartialEq)],
    // neither we implement PartialEq for it. That's why comparing Foo::Bar==a fails below.
    enum Foo2 {Bar}

    let a = Foo2::Bar;
    // Variable a matches Foo::Bar
    // ^-- this causes a compile-time error. Use `if let` instead.
    // if Foo2::Bar == a {
    //     println!("a is foobar");
    // }

    if let Foo2::Bar = a {
        println!("a is foobar");
    }

}

