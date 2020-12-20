#pragma once

/**
 @file
 Заголовочный файл, содержащий описание подсистемы, управляющей подписчиками.
 */

#include "publisher.hpp"

struct Controller {
  void setInput(std::istream *stream);

  void push(PublisherPtr subscriber);
  void execute();

private:
  std::istream *mSource;
  std::vector<PublisherPtr> mSubscribers;
};
