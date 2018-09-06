/*
 * Copyright (c) 2016 Steemit, Inc., and contributors.
 */
#pragma once

#define STEEMIT_BLOCKCHAIN_VERSION              ( version(0, 0, 0) ) // base on steem 0.19.5
#define STEEMIT_BLOCKCHAIN_HARDFORK_VERSION     ( hardfork_version( STEEMIT_BLOCKCHAIN_VERSION ) )

#ifdef IS_TEST_NET
#define STEEMIT_INIT_PRIVATE_KEY                (fc::ecc::private_key::regenerate(fc::sha256::hash(std::string("init_key"))))
#define STEEMIT_INIT_PUBLIC_KEY_STR             (std::string( steemit::protocol::public_key_type(STEEMIT_INIT_PRIVATE_KEY.get_public_key()) ))
#define STEEMIT_CHAIN_ID                        (fc::sha256::hash("testnet"))

#define VESTS_SYMBOL  (uint64_t(6) | (uint64_t('V') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< VESTS with 6 digits of precision
#define STEEM_SYMBOL  (uint64_t(3) | (uint64_t('T') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< TESTS with 3 digits of precision
#define STMD_SYMBOL   (uint64_t(3) | (uint64_t('T') << 8) | (uint64_t('S') << 16) | (uint64_t('T') << 24) | (uint64_t('D') << 32) ) ///< Test Dollars with 3 digits of precision

#define STEEMIT_SYMBOL                          "TEST"
#define STEEMIT_ADDRESS_PREFIX                  "TST"

#define STEEMIT_GENESIS_TIME                    (fc::time_point_sec(1451606400))
#define STEEMIT_MINING_TIME                     (fc::time_point_sec(1451606400))
#define STEEMIT_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define STEEMIT_SECOND_CASHOUT_WINDOW           (60*60*24*3) /// 3 days
#define STEEMIT_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24) /// 1 day
#define STEEMIT_VOTE_CHANGE_LOCKOUT_PERIOD      (60*10) /// 10 minutes
#define STEEMIT_UPVOTE_LOCKOUT                  (fc::minutes(5))


#define STEEMIT_MIN_ACCOUNT_CREATION_FEE          100

#define STEEMIT_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define STEEMIT_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define STEEMIT_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define STEEMIT_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1
#define STEEMIT_HARDFORK_REQUIRED_WITNESSES     1

#define STEEMIT_INIT_MINER_NAME                 "initminer"


#else // IS LIVE STEEM NETWORK

#define STEEMIT_INIT_PUBLIC_KEY_STR             "VIT6mEDy9EschxGjS1LJhb7zQrbmoWqrkg1n9fGiNfParFmC2mA9a"
//#define STEEMIT_CHAIN_ID                        (steemit::protocol::chain_id_type())
#define STEEMIT_CHAIN_ID                        (fc::sha256::hash("vit"))
#define VESTS_SYMBOL  (uint64_t(6) | (uint64_t('V') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< VESTS with 6 digits of precision
#define STEEM_SYMBOL  (uint64_t(3) | (uint64_t('V') << 8) | (uint64_t('I') << 16) | (uint64_t('T') << 24) ) ///< VIT with 3 digits of precision
#define STMD_SYMBOL   (uint64_t(3) | (uint64_t('V') << 8) | (uint64_t('I') << 16) | (uint64_t('T') << 24) | (uint64_t('D') << 32) ) ///< VIT Dollars with 3 digits of precision
#define STEEMIT_SYMBOL                          "VIT"
#define STEEMIT_ADDRESS_PREFIX                  "VIT"

#define STEEMIT_GENESIS_TIME                    (fc::time_point_sec(1458835200))
#define STEEMIT_MINING_TIME                     (fc::time_point_sec(1458838800))
#define STEEMIT_CASHOUT_WINDOW_SECONDS          (60*60*24*7)  /// 7 days
#define STEEMIT_SECOND_CASHOUT_WINDOW           (60*60*24*30) /// 30 days
#define STEEMIT_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24*14) /// 2 weeks
#define STEEMIT_VOTE_CHANGE_LOCKOUT_PERIOD      (60*60*2)     /// 2 hours
#define STEEMIT_UPVOTE_LOCKOUT                  (fc::hours(12))

#define STEEMIT_MIN_ACCOUNT_CREATION_FEE           100

#define STEEMIT_OWNER_AUTH_RECOVERY_PERIOD                  fc::days(30)
#define STEEMIT_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::days(1)
#define STEEMIT_OWNER_UPDATE_LIMIT                          fc::minutes(60)
#define STEEMIT_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 3186477
#define STEEMIT_HARDFORK_REQUIRED_WITNESSES     17 // 17 of the 21 dpos witnesses (20 elected and 1 virtual time) required for hardfork. This guarantees 75% participation on all subsequent rounds.

#define STEEMIT_INIT_MINER_NAME                 "vicewitness"

#define STEEMIT_HF_19_RECENT_CLAIMS (fc::uint128_t(uint64_t(140797515942543623ull)))

#endif

#define STEEMIT_BLOCK_INTERVAL                  3
#define STEEMIT_BLOCKS_PER_YEAR                 (365*24*60*60/STEEMIT_BLOCK_INTERVAL)
#define STEEMIT_BLOCKS_PER_DAY                  (24*60*60/STEEMIT_BLOCK_INTERVAL)
#define STEEMIT_START_VESTING_BLOCK             (STEEMIT_BLOCKS_PER_DAY * 7)
#define STEEMIT_START_MINER_VOTING_BLOCK        (STEEMIT_BLOCKS_PER_DAY * 30)

#define STEEMIT_NUM_INIT_MINERS                 1
#define STEEMIT_INIT_TIME                       (fc::time_point_sec());

#define STEEMIT_MAX_WITNESSES                   21

#define STEEMIT_MAX_VOTED_WITNESSES_HF0         19
#define STEEMIT_MAX_MINER_WITNESSES_HF0         1
#define STEEMIT_MAX_RUNNER_WITNESSES_HF0        1

#define STEEMIT_MAX_VOTED_WITNESSES_HF17        20
#define STEEMIT_MAX_MINER_WITNESSES_HF17        0
#define STEEMIT_MAX_RUNNER_WITNESSES_HF17       1

#define STEEMIT_MAX_TIME_UNTIL_EXPIRATION       (60*60) // seconds,  aka: 1 hour
#define STEEMIT_MAX_MEMO_SIZE                   2048
#define STEEMIT_MAX_PROXY_RECURSION_DEPTH       4
#define STEEMIT_VESTING_WITHDRAW_INTERVALS      13
#define STEEMIT_VESTING_WITHDRAW_INTERVAL_SECONDS (60*60*24*7) /// 1 week per interval
#define STEEMIT_MAX_WITHDRAW_ROUTES             10
#define STEEMIT_SAVINGS_WITHDRAW_TIME        	(fc::days(3))
#define STEEMIT_SAVINGS_WITHDRAW_REQUEST_LIMIT  100
#define STEEMIT_VOTE_REGENERATION_SECONDS       (5*60*60*24) // 5 day
#define STEEMIT_MAX_VOTE_CHANGES                5
#define STEEMIT_REVERSE_AUCTION_WINDOW_SECONDS  (60*30) /// 30 minutes
#define STEEMIT_MIN_VOTE_INTERVAL_SEC           3
#define STEEMIT_VOTE_DUST_THRESHOLD             (50000) // 50000000

#define STEEMIT_MIN_ROOT_COMMENT_INTERVAL       (fc::seconds(60*5)) // 5 minutes
#define STEEMIT_MIN_REPLY_INTERVAL              (fc::seconds(20)) // 20 seconds
#define STEEMIT_POST_AVERAGE_WINDOW             (60*60*24u) // 1 day
#define STEEMIT_POST_MAX_BANDWIDTH              (4*STEEMIT_100_PERCENT) // 2 posts per 1 days, average 1 every 12 hours
#define STEEMIT_POST_WEIGHT_CONSTANT            (uint64_t(STEEMIT_POST_MAX_BANDWIDTH) * STEEMIT_POST_MAX_BANDWIDTH)

#define STEEMIT_MAX_ACCOUNT_WITNESS_VOTES       30

#define STEEMIT_100_PERCENT                     10000
#define STEEMIT_1_PERCENT                       (STEEMIT_100_PERCENT/100)
#define STEEMIT_1_TENTH_PERCENT                 (STEEMIT_100_PERCENT/1000)

#define STEEMIT_INFLATION_RATE_START_PERCENT    (978)
#define STEEMIT_INFLATION_RATE_STOP_PERCENT     (95) // 0.95%
#define STEEMIT_INFLATION_NARROWING_PERIOD      (125000) // Narrow 0.01% every 125k blocks
#define STEEMIT_CONTENT_REWARD_PERCENT          (75*STEEMIT_1_PERCENT) //75% of inflation
#define STEEMIT_VESTING_FUND_PERCENT            (15*STEEMIT_1_PERCENT) //15% of inflation, 1.425% inflation
#define STEEMIT_CURATION_REWARD_PERCENT         (40*STEEMIT_1_PERCENT)  // % of STEEMIT_CONTENT_REWARD_PERCENT

#define STEEMIT_MINER_PAY_PERCENT               (STEEMIT_1_PERCENT) // 1%
#define STEEMIT_MIN_RATION                      100000
#define STEEMIT_MAX_RATION_DECAY_RATE           (1000000)
#define STEEMIT_FREE_TRANSACTIONS_WITH_NEW_ACCOUNT 100

#define STEEMIT_BANDWIDTH_AVERAGE_WINDOW_SECONDS (60*60*24*7) ///< 1 week
#define STEEMIT_BANDWIDTH_PRECISION             (uint64_t(1000000)) ///< 1 million
#define STEEMIT_MAX_COMMENT_DEPTH               0xffff // 64k
#define STEEMIT_SOFT_MAX_COMMENT_DEPTH          0xff // 255

#define STEEMIT_MAX_RESERVE_RATIO               (20000)

#define STEEMIT_CREATE_ACCOUNT_WITH_STEEM_MODIFIER 30
#define STEEMIT_CREATE_ACCOUNT_DELEGATION_RATIO    5
#define STEEMIT_CREATE_ACCOUNT_DELEGATION_TIME     fc::days(30)

#define STEEMIT_MINING_REWARD                   asset( 1000, STEEM_SYMBOL )
#define STEEMIT_MIN_PRODUCER_REWARD             STEEMIT_MINING_REWARD

#define STEEMIT_ACTIVE_CHALLENGE_FEE            asset( 2000, STEEM_SYMBOL )
#define STEEMIT_OWNER_CHALLENGE_FEE             asset( 30000, STEEM_SYMBOL )
#define STEEMIT_ACTIVE_CHALLENGE_COOLDOWN       fc::days(1)
#define STEEMIT_OWNER_CHALLENGE_COOLDOWN        fc::days(1)

#define STEEMIT_POST_REWARD_FUND_NAME           ("post")
#define STEEMIT_RECENT_RSHARES_DECAY_RATE_HF19  (fc::days(15))
#define STEEMIT_CONTENT_CONSTANT_HF0            (uint128_t(uint64_t(2000000000000ll)))

#define STEEMIT_MIN_PAYOUT                      (asset(20,STEEM_SYMBOL))

#define STEEMIT_MIN_ACCOUNT_NAME_LENGTH          3
#define STEEMIT_MAX_ACCOUNT_NAME_LENGTH         16

#define STEEMIT_MIN_PERMLINK_LENGTH             0
#define STEEMIT_MAX_PERMLINK_LENGTH             256
#define STEEMIT_MAX_WITNESS_URL_LENGTH          2048

#define STEEMIT_INIT_SUPPLY                     int64_t(4000000000000ll)
#define STEEMIT_MAX_SHARE_SUPPLY                int64_t(1000000000000000ll)
#define STEEMIT_MAX_SIG_CHECK_DEPTH             2

#define STEEMIT_MIN_TRANSACTION_SIZE_LIMIT      1024
#define STEEMIT_SECONDS_PER_YEAR                (uint64_t(60*60*24*365ll))

#define STEEMIT_MAX_TRANSACTION_SIZE            (1024*64)
#define STEEMIT_MIN_BLOCK_SIZE_LIMIT            (STEEMIT_MAX_TRANSACTION_SIZE)
#define STEEMIT_MAX_BLOCK_SIZE                  (STEEMIT_MAX_TRANSACTION_SIZE*STEEMIT_BLOCK_INTERVAL*2000)
#define STEEMIT_MIN_BLOCK_SIZE                  115
#define STEEMIT_BLOCKS_PER_HOUR                 (60*60/STEEMIT_BLOCK_INTERVAL)

#define STEEMIT_MIN_UNDO_HISTORY                10
#define STEEMIT_MAX_UNDO_HISTORY                10000

#define STEEMIT_MIN_TRANSACTION_EXPIRATION_LIMIT (STEEMIT_BLOCK_INTERVAL * 5) // 5 transactions per block
#define STEEMIT_BLOCKCHAIN_PRECISION            uint64_t( 1000 )

#define STEEMIT_BLOCKCHAIN_PRECISION_DIGITS     3
#define STEEMIT_MAX_INSTANCE_ID                 (uint64_t(-1)>>16)
/** NOTE: making this a power of 2 (say 2^15) would greatly accelerate fee calcs */
#define STEEMIT_MAX_ASSET_WHITELIST_AUTHORITIES 10
#define STEEMIT_MAX_URL_LENGTH                  127

#define STEEMIT_IRREVERSIBLE_THRESHOLD          (75 * STEEMIT_1_PERCENT)
#define VIRTUAL_SCHEDULE_LAP_LENGTH2 ( fc::uint128::max_value() )

/**
 *  Reserved Account IDs with special meaning
 */
///@{
/// Represents the current witnesses
#define STEEMIT_MINER_ACCOUNT                   "miners"
/// Represents the canonical account with NO authority (nobody can access funds in null account)
#define STEEMIT_NULL_ACCOUNT                    "null"
/// Represents the canonical account with WILDCARD authority (anybody can access funds in temp account)
#define STEEMIT_TEMP_ACCOUNT                    "temp"
/// Represents the canonical account for specifying you will vote for directly (as opposed to a proxy)
#define STEEMIT_PROXY_TO_SELF_ACCOUNT           ""
/// Represents the canonical root post parent account
#define STEEMIT_ROOT_POST_PARENT                (account_name_type())
///@}

