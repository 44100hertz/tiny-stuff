// vim.rs bug: indentation
//
// In any expression contained in parens (tuple assignment, function calls), wherein the opening
// line of the function contains a closing paren, even in a comment, any further lines of the
// expression are not indented.

fn main() {
    let a = A;
    // case 1: no parens inside dothing, ok
    dothing(1 * 2,
            1);
    // case 2: inner dothing on newline, ok
    dothing(
        dothing() * 2,
        1);
    // case 3: no newline and parens, err
    dothing(dothing() * 2,
    1);
    // case 4: same bug applies to methods
    dothing(thingdoer.dothing() * 2,
    1);
    // case 5: or to any parens in general
    dothing((8) * 2,
    1);
    // case 6: comment parens (really?)
    dothing(2, // )
    );

    // case 7: tuple assignments are the same
    let (x, y) = ((100),
    200);
}

