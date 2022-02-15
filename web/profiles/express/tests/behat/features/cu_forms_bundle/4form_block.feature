@webform
Feature: Webform Blocks
When a Webform has been created
As a user with the proper role
I should be able to export a Webform Block

# 1) TEST WEBFORM BLOCK CREATION
# 2) WRAP THE WEBFORM BLOCK IN A BEAN WRAPPER


# 1) TEST WEBFORM BLOCK CREATION
Scenario: A Webform can be exported as a block
Given I am logged in as a user with the "site_owner" role
And I am on "admin/content/webform"
And I follow "Simple Test Form"
And I follow "Edit Webform"
And I follow "Form settings"
Then I should see an "#edit-advanced" element
And I should see "If enabled this webform will be available as a block."
And the "edit-block" checkbox should not be checked
And I check "edit-block"
And I press "Save configuration"
Then I should see "The form settings have been updated."
And I follow "Edit"
And I press "Cancel edit"

# 2) WRAP THE WEBFORM BLOCK IN A BEAN WRAPPER
Scenario: The Webform block, created above, can be wrapped in a bean wrapper
Given I am logged in as a user with the "site_owner" role
And I am on "block/add/block-wrapper"
And I fill in "edit-label" with "Simple Test Form Block"
And I select "Webform: Simple Test Form" from "edit-field-block-wrapper-reference-und"
When I press "Save"
Then I should see "Block Wrapper Simple Test Form Block has been created."
When I go to "admin/content/blocks"
Then I should see "Simple Test Form Block"
