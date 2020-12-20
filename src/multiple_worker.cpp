#include "multiple_worker.hpp"

void MultipleWorker::job(const std::string &command) {
  // Add if open block only.
  if (mBlockCount)
    mCommands.add(command);
}

void MultipleWorker::openBrace() {
  if (!mBlockCount)
    mTime = std::time(nullptr);
  mBlockCount++;
}

void MultipleWorker::closeBrace() {
  if (mBlockCount)
    mBlockCount--;

  // Dump if end the block.
  if (!mBlockCount)
    dump();
}

PublisherPtr MultipleWorker::createWorker() {
  return std::make_shared<MultipleWorker>();
}
