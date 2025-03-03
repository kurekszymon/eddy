#!/bin/bash

HOOKS_DIR=".git/hooks"
COMMIT_MSG_HOOK="scripts/git/hooks/commit-msg"
TARGET_COMMIT_MSG_HOOK="$HOOKS_DIR/commit-msg"

if [ ! -d "$HOOKS_DIR" ]; then
  echo "Error: .git/hooks directory not found. Make sure this is a valid git repository."
  exit 1
fi

echo "Installing commit-msg hook..."
cp "$COMMIT_MSG_HOOK" "$TARGET_COMMIT_MSG_HOOK"

echo $TARGET_COMMIT_MSG_HOOK

chmod +x "$TARGET_COMMIT_MSG_HOOK"

echo "commit-msg hook has been installed successfully!"

if [ -x "$TARGET_COMMIT_MSG_HOOK" ]; then
  echo "The commit-msg hook is executable and ready to use."
else
  echo "Error: Failed to set the commit-msg hook as executable."
  exit 1
fi