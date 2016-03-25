#include "MaxSizeReplPolicy.h"

void MaxSizeReplPolicy::Insert(const CacheEntry& entry) {
  prio_queue_.push(MaxSizeEntry(entry.getKey(), entry.getSize()));
}

void MaxSizeReplPolicy::Touch(const CacheEntry& entry) {

}

std::string MaxSizeReplPolicy::RemoveReplacement() {
  std::string key = prio_queue_.top().getKey();
  prio_queue_.pop();
  return key;
}

void MaxSizeReplPolicy::Reset() {
  prio_queue_ = std::priority_queue<MaxSizeEntry>();
}
