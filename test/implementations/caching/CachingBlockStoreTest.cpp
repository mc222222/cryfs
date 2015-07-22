#include "../../../implementations/caching/CachingBlockStore.h"
#include "../../../implementations/testfake/FakeBlockStore.h"
#include "../../testutils/BlockStoreTest.h"
#include "google/gtest/gtest.h"


using blockstore::BlockStore;
using blockstore::caching::CachingBlockStore;
using blockstore::testfake::FakeBlockStore;
using cpputils::unique_ref;
using cpputils::make_unique_ref;

class CachingBlockStoreTestFixture: public BlockStoreTestFixture {
public:
  unique_ref<BlockStore> createBlockStore() override {
    return make_unique_ref<CachingBlockStore>(make_unique_ref<FakeBlockStore>());
  }
};

INSTANTIATE_TYPED_TEST_CASE_P(Caching, BlockStoreTest, CachingBlockStoreTestFixture);

//TODO Add specific tests for the blockstore