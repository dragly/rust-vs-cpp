
// Task 3: Observe that Guard is movable, yet
// manages to lock and unlock exactly once without
// doing this by runtime bookkeeping. How can this be?
// Tip: Compile with `rustc TypicalResourceHolder.rs`.
//
// Task 4: Have fun uncommenting the use after move
// and the second mutable borrow.

fn main()
{
    let mut mutex = MockMutex{ locked: false };

    let guard1 = Guard::new(&mut mutex);
    // let guard2 = Guard::new(&mut mutex); // second mutable borrow

    let _move1 = guard1;
    // let _move2 = guard1; // use after move
}

struct Guard<'a>
{
    mutex: &'a mut MockMutex,
}

impl<'a> Guard<'a> {
    fn new(mutex: &mut MockMutex) -> Guard
    {
        mutex.lock();
        Guard { mutex }
    }
}

impl<'a> Drop for Guard<'a> {
    fn drop(&mut self)
    {
        self.mutex.unlock();
    }
}

struct MockMutex{
    locked: bool,
}

impl MockMutex {
    fn lock(&mut self) {
        if self.locked {
            panic!("Already locked");
        }
        self.locked = true;
    }
    fn unlock(&mut self) {
        if !self.locked {
            panic!("Not already locked");
        }
        self.locked = false;
    }
}
