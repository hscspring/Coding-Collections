#[derive(Debug)]
struct Person<'a> {
    // The 'a defines a lifetime
    name: &'a str,
    age: u8,
}

// A unit struct
struct Nil;

// A tuple struct
struct Pair(i32, f32);

// A struct with two fields
struct Point {
    x: f32,
    y: f32,
}

// Structs can be reused as fields of another struct
#[allow(dead_code)]
struct Rectangle {
    // A rectangle can be specified by where the top left and bottom right
    // corners are in space.
    top_left: Point,
    bottom_right: Point,
}

fn rect_area(rect: Rectangle) -> f32 {
    let Rectangle {
        top_left: Point {
            x: x0, y: y0,
        },
        bottom_right: Point {
            x: x1, y: y1,
        }
    } = rect;
    (y1 - y0).abs() * (x1 - x0).abs()
}

fn square(point: Point, arg: f32) -> Rectangle {
    let Point { x: left_edge, y: lower_edge } = point;
    Rectangle {
        top_left: Point {
            x: left_edge, y: lower_edge + arg,
        },
        bottom_right: Point {
            x: left_edge + arg, y: lower_edge,
        }
    }
}


fn main() {
    // create struct with field init shorthand
    let name = "Peter";
    let age = 27;
    let peter = Person { name, age };

    // print debug struct
    println!("{:?}", peter);

    // instantiate a Point
    let point: Point = Point { x: 10.3, y: 0.4 };
    println!("point coordinates: ({}, {})", point.x, point.y);

    // use the other one's field
    let bottom_right = Point { x: 5.2, ..point};
    println!("second point: ({}, {})", bottom_right.x, bottom_right.y);

    // Destructure the point using a let binding
    let Point { x: top_edge, y: left_edge } = point;
    let rectangle = Rectangle {
        top_left: Point { x: left_edge, y: top_edge },
        bottom_right: bottom_right,
    };

    // instantiate a unit struct
    let _nil = Nil;

    // instantiate a tuple struct
    let pair = Pair(1, 0.1);
    println!("pair contains {:?} and {:?}", pair.0, pair.1);

    // destructure a tuple struct
    let Pair(integer, decimal) = pair;
    println!("pair contains {:?} and {:?}", integer, decimal);

    let area = rect_area(rectangle);
    println!("area: {}", area);

    let zero: Point = Point { x: 0.0, y: 0.0 };
    let rect: Rectangle = square(zero, 2f32);

    println!("area: {}", rect_area(rect));
}