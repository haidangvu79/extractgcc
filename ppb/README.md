![Pipeline status badge](https://git.frama-c.com/pub/open-source-case-studies/badges/master/pipeline.svg)

Open source case studies for Frama-C
====================================

This repository is a collection of open source C codes to be used with
[Frama-C](http://frama-c.com), in particular with the Eva
(Evolved Value Analysis) plug-in.

Most directories contain open-source code that constitutes a "case study".
A few contain sets of tests, benchmarks or tutorials.


# Requirements

- GNU Make >= 4.0;
- (optional, for some scripts) Python >= 3.7.

# Basic usage

- (required once) `make submodules`: initializes the local Frama-C submodule;
- (required once) `make framac`: prepares a git submodule with a clone
  of the public git of Frama-C, compiles it and installs it locally
  (in `frama-c/build/bin`);
- (required once) add the following alias to your shell:

        alias fcmake='make -C .frama-c'

  Each "case study" contains a `.frama-c` subdirectory with the Frama-C
  Makefile. Running `fcmake` will run Frama-C related targets;
  running `make` will run the case study's original Makefile (if it exists).
- `cd` to the subdirectory of one of the case studies;
  We recommend `2048` for a short and fast analysis, or `debie1` for
  a finalized analysis.
- Run `fcmake` to parse and run Eva on the predefined targets.

## Makefile targets

The scripts provided with Frama-C create several Makefile targets,
according to the intended usage. The main ones are:

- `display-targets`: lists the base targets
- For each base target `t`, the following targets are generated:
  - `t.parse`: parse the sources;
  - `t.eva`: run Eva;
  - `t.eva.gui`: open the GUI.

Each target depends on the previous one: running `t.eva.gui` will
automatically run `t.eva` if required; the same for `t.parse`.

Other generated targets:

- `t.parse.gui`: open the GUI with the result of the parsing, *without* running
  Eva. Mostly useful in conjunction with other plug-ins.
- `t.stats`: print time/memory usage.

### Remarks

- The output of `t.eva` is verbose, but you can ignore it;
  the important information (warnings and alarms) can be inspected via the GUI.
- The result of the analysis is stored inside `.frama-c`, in subdirectories
  `t.parse` for parsing and `t.eva` for the Eva analysis.
  Each subdirectory contains a few log files.
- To try other parametrizations, simply edit variables
  `CPPFLAGS/FCFLAGS/EVAFLAGS` in `.frama-c/GNUmakefile` and re-run `fcmake`.

# Notes

A summary of the case studies, with a brief description, URL, number of Eva
targets, etc, is available at [summary.md](summary.md).

## Source code modifications

We attempt to minimize changes to each case study, to keep the code close to
the original. Here are the most common kinds of changes:

- A `.frama-c` directory is added, with a `GNUmakefile` which defines the
  Frama-C targets and parameters;
- Some stubs file (e.g. `stubs.c`) are added to the `.frama-c` directory,
  either to emulate an initial state with command-line arguments, or to provide
  code/specifications for library functions, missing code, non-portable
  features, etc.
- When code modifications are needed (and cannot be moved to the stubs file,
  e.g. when adding a specification to a `static` functions), we often
  protect them by `#ifdef __FRAMAC__` guards, to ensure the code compiles
  as before when not using Frama-C. Note that this is not always the case.
- Some unnecessary files for the analysis (e.g. documentation, project setups
  for IDEs, non-code resources) are removed.
- Some Makefiles were renamed `Makefile.original`, and a simplified
  OSCS-related `Makefile` has been added. This enables compiling some targets
  in a way that is useful for certain build tools.

In case studies related to benchmarking, examples or test suites, we often
apply modifications more liberally.

## Rationale

The main objectives of these files are:

1. Non-regression tests;
2. Benchmarking;
3. Practical examples.

Therefore, some of the code bases are voluntarily parametrized with
suboptimal parameters, for non-regression testing. Some code bases undergo
partial, progressive improvements.
Only a few constitute "finalized" case studies.

# Contributions

If you know of other open source code bases where Frama-C/Eva produces
interesting results, please contribute with pull requests including the
case study sources and your `.frama-c/GNUmakefile`.

On the other hand, if you have some interesting open-source C software
(ideally, C99-compatible) that you are unable to parse and/or run with
Frama-C/Eva, consider creating an issue in this repository¹
with the description of the problem you are facing (e.g. missing/incompatible
declarations in the Frama-C libc, problems when preprocessing/parsing the
code, constructs unsupported by Eva, etc).
Ideally, create a (WIP) pull request with the sources in a new directory,
ready to be prepared for the case study.

¹ *Note*: direct account creation is disabled in Frama-C's Gitlab; linking
  a Github account is always possible.


# License

License files are kept in each directory where they were originally found,
when available. We also summarize the license of each directory below.

- `2048`: MIT
- `basic-cwe-examples`: see `LICENSE`
- `bench-moerman2018`: MIT
- `c-testsuite`: see `LICENSE` and `LICENSE-tests`
- `cerberus`: see `LICENSE`
- `chrony`: GPL
- `debie1`: distribution and use authorized by Patria Aviation Oy,
            Space Systems Finland Ltd. and Tidorum Ltd, see `README.txt`
            and `terms_of_use-2014-05.pdf`
- `genann`: Zlib, see `LICENSE`
- `gzip124`: GPL
- `hiredis`: Redis license (BSD-style), see `COPYING`
- `icpc`: Unlicense
- `ioccc`: Creative Commons Attribution-ShareAlike 3.0 Unported (CC BY-SA 3.0),
           see `COPYING`
- `itc-benchmarks`: BSD 2-clause, see `COPYING`
- `jsmn`: MIT
- `kgflags`: MIT, see `LICENSE`
- `khash`: MIT
- `kilo`: BSD 2-clause "Simplified", see `LICENSE`
- `libmodbus`: LGPL
- `libspng`: BSD 2-clause, see `LICENSE`
- `libyaml`: MIT, see `License`
- `line-following-robot`: MIT + modified BSD (for included `avr-libc`),
                          see `LICENSE` and `avr-libc/include/LICENSE`
- `mibench`: several, see `LICENSE` file inside each subdirectory
- `mini-gmp`:  LGPL or GPL
- `miniz`:  MIT
- `microstrain`: GPL and others, see `LICENSE`
- `monocypher`: see `README`
- `papabench`: GPL
- `polarssl`: GPL
- `qlz`: GPL
- `safestringlib`: MIT
- `semver`: MIT
- `solitaire`: public domain, see `solitaire.c`
- `stmr`: MIT
- `tsvc`: MIT, see `license.txt`
- `tweetnacl-usable`: public domain, see `LICENSE.txt`
- `verisec`: several, according to each app
- `x509-parser` : GPLv2 / BSD, see `LICENSE`


# Troubleshooting / Debugging

(This section is mainly for Frama-C/plug-in developers who want to test OSCS
with specific versions of Frama-C)

OSCS can work in different modes:

1. With a local Frama-C, installed via the Git submodule 'frama-c'
   (after running `make framac`);
2. With another, locally-installed Frama-C;
3. With Frama-C installed in the PATH.

This behavior is defined in `path.mk`. This file is included (as a symbolic
link) in the `.frama-c` directory for each case study. Changing this file will
change the behavior of all case studies.

- Mode 1 (by default) is enabled as soon as `make framac` is executed.
- To enable mode 2, modify the `FRAMAC_DIR=` line in `path.mk` to point to the
  `bin` directory of your locally installed Frama-C.
- To enable mode 3, simply comment the `FRAMAC_DIR=` line.

If the value of `FRAMAC_DIR` is invalid (does not point to an existing
directory), an error will be raised.

If you need help debugging, consider adding messages such as
`$(info FRAMAC_DIR is: $(FRAMAC_DIR))` to `path.mk`.
When running one of the `make` targets, these messages might help understand
if the path has been properly set.
