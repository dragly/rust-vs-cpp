// Noncopyable by default
struct Resource
{
    data: usize
}

impl Resource
{
    fn from_string(input: &str) -> Resource
    {
        Resource{
            data: input.len()
        }
    }

    fn from_number(input: usize) -> Resource
    {
        Resource{
            data: input
        }
    }

    fn print(&self)
    {
        println!("data = {}", self.data)
    }
}

fn should_the_string_be_used() -> bool
{
  return true;
}

fn main() {
    let str_input = "hello";
    let number_input = 7;

    let r = if should_the_string_be_used() {
        Resource::from_string(str_input)
    } else {
        Resource::from_number(number_input)
    };

    r.print();
}
