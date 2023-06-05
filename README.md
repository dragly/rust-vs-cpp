# rust-vs-cpp

Examples where Rust is safer, more elegant or more efficient than C++

# Using Docker

If you are happy to use your own environment, skip this step.

If you prefer using Docker instead of running the setup script on your own system environment,
run the following command to launch a Docker environment:

```bash
docker run --mount type=bind,source=(pwd),target=/src --workdir /src --interactive --tty ubuntu:22.04 bash
```

Next, follow the instructions below.

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
