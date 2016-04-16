cutieboy-color
===================
This is a gameboy color game project. I will run my development here, after a project is ready, I'll move it to it's own repository.


Requirements
------------
- sdcc (from your favourite package manager)
- [gbdk-n](https://github.com/rotmoset/gbdk-n)
- vbam (optional)

Setup
-----

- Install requirements
- Make sure `bin` folder of gbdk-n is in your environment path

Usage
-----
- To build your code, run:
```bash
    make
```
- To clean your environment, run:
```bash
    make clean
```
- To test your game (needs vbam), after you build your code, run:
```bash
    make test
```