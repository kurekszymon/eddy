# eddy.sh 

with this project I wanted to help developers onboard a new team with certain set of tools. 

Most of the time documentation is outdated on how to setup certain project, or it is all over the confluence and README files. ***eddy.sh*** is my idea of centralizing dev onboarding to a single `yaml` file with all the tools needed per specific project. 

***eddy.sh*** supports 
- cloning repositories to declared destination
- running your own custom scripts within the app
- set of tools per each language 

## How to use 

Head to releases section and download ***eddy.sh*** (TODO - create releases 😅) and use example yaml or create your own. 

__IMPORTANT__ example yaml will contain all supported keys, if your desired tool is not on the list - please raise an issue on GitHub, or use _custom\_scripts_ section to provide custom instructions on how to install your tool. 

## How to contribute 

In future, ***eddy.sh*** should be self sustainable meaning you could setup working on ***eddy.sh*** using released version. 

For now: 

### MacOS 
*ensure you don't use system's python version to apply packages globally*

```bash
python -m pip install conan 
brew install cmake ninja llvm
echo 'export PATH="/opt/homebrew/opt/llvm/bin:$PATH"' >> ~/.zshrc # to ensure llvm tools like clang-tidy are in $PATH
```

### Windows | Linux 
***note: I didn't build it on Windows or Linux yet, my guess is just use python for everything***

```bash
python -m pip install conan cmake ninja
```

### HOW TO BUILD

Install conan dependencies using 
`./scripts/conan_install.sh`
then build the project with 
`./scripts/build.sh`

or use tasks: `install eddy deps` and `build eddy` in vscode. 

### HOW TO RUN 
```sh
./scripts/run.sh
```
or use task: `run eddy` in vscode


### Git scripts

to have git scripts initialized run `scripts/setup_hooks` 
it will check if you used one of keywords to close github issue, 
if such issue doesn't exist you can bypass it by passing `--no-verify` flag, like

`git commit -m 'random message' --no verify`