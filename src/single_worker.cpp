#include "single_worker.hpp"

SingleWorker::SingleWorker(size_t bulkSize) : mBulkSize(bulkSize) {
  mCommands = Container(bulkSize);
}

SingleWorker::~SingleWorker() {
  if (!mCommands.isEmpty())
    dump();
}

void SingleWorker::addCommand(const std::string &command) {
  mCommands.add(command);
}

void SingleWorker::openBrace() {
  if (!mBlockCount && !mCommands.isEmpty())
    dump();

  mBlockCount++;
}

void SingleWorker::closeBrace() {
  if (mBlockCount)
    mBlockCount--;
}

void SingleWorker::job(const std::string &command) {
  if (!mBlockCount) {
    if (mCommands.isEmpty())
      mTime = std::time(nullptr);
    addCommand(command);

    // The limit has been reached.
    if (mBulkSize == mCommands.size())
      dump();
  }
}

PublisherPtr SingleWorker::createWorker(int bulkSize) {
  return std::make_shared<SingleWorker>(bulkSize);
}
