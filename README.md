# rust-vs-cpp

Examples where Rust is safer, more elegant or more efficient than C++

# Setup

Run the following command to install dependencies.
However, it is recommended to look at the setup script and install what you need manually
to avoid overriding any configuration you have from before.

```bash
bash setup.sh
```

# Running Rust and C++ examples

The examples are run with a run script by passing a configuration and
the name of the examples:

```bash
run.sh uninitialized-cpp Release
```

```bash
run.sh uninitialized-rust Debug
```

# Important

Some of the examples are meant to fail when building or running them.
For instance, `uninitialized-rust` is meant to show that the Rust compiler
will not let you use an uninitialized variable and will fail with a
corresponding error message.