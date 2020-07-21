extern crate minigrep2;

use std::env;
use std::process;

use minigrep2::Config;

fn main() {
    let config = Config::new(env::args()).unwrap_or_else(|err| {
        eprintln!("Problem parsing arguments {}", err);
        process::exit(1);
    });

    if let Err(e) = minigrep2::run(config) {
        eprintln!("App error: {}", e);
        process::exit(1);
    }
}
