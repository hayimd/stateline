stateline
=========
Stateline is a framework for distributed Markov Chain Monte Carlo (MCMC) sampling written in C++11. It focuses on [parallel tempering](http://en.wikipedia.org/wiki/Parallel_tempering) methods which are highly parallelisable.

System Support
--------------
Currently, Stateline runs on Linux-based operating systems only.

Compiler Support
----------------
Stateline has been compiled and tested under g++ 4.8.2.

Prerequisites
-------------
Stateline requires the following libraries as prerequisites:

* Boost 1.55
* Eigen 3.2.0
* google-log (glog) 0.3.3
* google-test (gtest) 1.7.0
* zeromq 4.0.3
* cppzeromq 2358037407 (commit hash)

Building
--------
The simplest way to get Stateline running is to run the `fetch-all.sh` script in the project root directory:

```bash
$ git clone https://github.com/NICTA/stateline.git
$ cd stateline && bash fetch-all.sh
$ cd build && make -j8
$ make run-test-all
```

This will automatically download the necessary dependencies into a build folder. There are also more [advanced](https://github.com/NICTA/stateline/wiki/Installation-Guide) build instructions.

Running C++ Demo
----------------
To see Stateline in action, open two terminals and run the following commands in the build directory:

Run the Stateline server in Terminal 1:

```bash
$ ./stateline --config=demo-cpp-config.json
```

Run a Stateline worker in Terminal 2:

```bash
$ ./demoWorker
```

Now, in your build directory, you should see a folder called cpp-demo-chains. This folder contains samples from the demo MCMC. Running

```bash
$ python vis.py cpp-demo-chains/0.csv
```

will run a Python script that visualises the samples.

Running Python Demo
-------------------
There is also a demo in Python, which shows how workers written in other languages can interact with the Stateline server. Again, open two terminals and run the following commands in the build directory:

Run the Stateline server in Terminal 1:

```bash
$ ./stateline --config=demo-python-config.json
```

Run a Stateline worker in Terminal 2:

```bash
$ python demo-worker.py
```

And again, running

```bash
$ python vis.py python-demo-chains/0.csv
```

will run a Python script that visualises the samples.

Documentation
-------------
Documentation can be found in the
[wiki](http://github.com/NICTA/stateline/wiki), and there is automatic doxygen documentation generated by running

```bash
$ make doc
```

int the build directory. Please ensure Doxygen is installed. Finally, there are demos for python and C++ in the src/bin folder.

Licence
-------
Please see the LICENSE file, and COPYING and COPYING.LESSER.

Bug Reports
-----------
If you find a bug, please open an [issue](http://github.com/NICTA/stateline/issues).

Contributing 
------------
Contributions and comments are welcome. Please read our [style guide](docs/CodeGuidelines.md) before submitting a pull request.
