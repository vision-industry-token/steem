#pragma once

#include <steemit/protocol/operation_util.hpp>
#include <steemit/protocol/steem_operations.hpp>
#include <steemit/protocol/steem_virtual_operations.hpp>

namespace steemit { namespace protocol {

   /** NOTE: do not change the order of any operations prior to the virtual operations
    * or it will trigger a hardfork.
    */
   typedef fc::static_variant<
            vote_operation,
            comment_operation,

            transfer_operation,
            transfer_to_vesting_operation,
            withdraw_vesting_operation,

            no_operation_00,
            no_operation_01,

            no_operation_02,
            no_operation_03,

            account_create_operation,
            account_update_operation,

            witness_update_operation,
            account_witness_vote_operation,
            account_witness_proxy_operation,

            no_operation_04,

            custom_operation,

            report_over_production_operation,

            delete_comment_operation,
            custom_json_operation,
            comment_options_operation,
            set_withdraw_vesting_route_operation,
            no_operation_05,
            challenge_authority_operation,
            prove_authority_operation,
            request_account_recovery_operation,
            recover_account_operation,
            change_recovery_account_operation,
            escrow_transfer_operation,
            escrow_dispute_operation,
            escrow_release_operation,
            no_operation_06,
            escrow_approve_operation,
            transfer_to_savings_operation,
            transfer_from_savings_operation,
            cancel_transfer_from_savings_operation,
            custom_binary_operation,
            decline_voting_rights_operation,
            no_operation_07,
            no_operation_08,
            claim_reward_balance_operation,
            delegate_vesting_shares_operation,
            account_create_with_delegation_operation,

            /// virtual operations below this point
            no_operation_09,
            author_reward_operation,
            curation_reward_operation,
            comment_reward_operation,
            no_operation_10,
            no_operation_11,
            fill_vesting_withdraw_operation,
            no_operation_12,
            shutdown_witness_operation,
            fill_transfer_from_savings_operation,
            hardfork_operation,
            comment_payout_update_operation,
            return_vesting_delegation_operation,
            comment_benefactor_reward_operation,
            producer_reward_operation
         > operation;

   /*void operation_get_required_authorities( const operation& op,
                                            flat_set<string>& active,
                                            flat_set<string>& owner,
                                            flat_set<string>& posting,
                                            vector<authority>&  other );

   void operation_validate( const operation& op );*/

   bool is_market_operation( const operation& op );

   bool is_virtual_operation( const operation& op );

} } // steemit::protocol

/*namespace fc {
    void to_variant( const steemit::protocol::operation& var,  fc::variant& vo );
    void from_variant( const fc::variant& var,  steemit::protocol::operation& vo );
}*/

DECLARE_OPERATION_TYPE( steemit::protocol::operation )
FC_REFLECT_TYPENAME( steemit::protocol::operation )
