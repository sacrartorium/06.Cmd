#pragma once

/**
 @file
 Заголовочный файл, описывающий работу с группами команд.
 */

#include "publisher.hpp"

struct MultipleWorker : public Publisher {
  static PublisherPtr createWorker();

private:
  void openBrace() override;
  void closeBrace() override;

  void job(const std::string &command) override;
};
