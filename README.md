### requirements 

conan
```bash
python3 -m pip install pipx
python3 -m pipx install conan 
python3 -m pipx ensurepath
```

CMake
`brew install cmake`

Ninja
`brew install ninja`


### quirks and features 

if some library is not found try running 
`conan install conanfile.txt --build <rm>`
you dummy

### HOW TO BUILD

```sh
./scripts/conan_install.sh
./scripts/build.sh
```
or use tasks: `install eddy deps` and `build eddy` in vscode. 

### HOW TO RUN 
```sh
./scripts/run.sh
```
or use task: `run eddy` in vscode


### Git scripts

to have git scripts run `scripts/setup_hooks` 
it will check if you used one of keywords to close github issue, 
if such issue doesn't exist you can bypass it by passing `--no-verify` flag, like

`git commit -m 'random message' --no verify`