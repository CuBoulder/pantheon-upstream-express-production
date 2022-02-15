@digital_campaign @ab_testing
Feature: A/B Testing
In order to test the results of a digital campaign
A user with the proper role
Should be able to access, create and run A/B tests

Scenario: A/B Block has been added to the Blocks page
  Given I am logged in as a user with the "site_owner" role
  And I am on "block/add"
  Then I should see the link "A/B Block"

@javascript
Scenario: An A/B test can be created and its content served according to set percentages
  Given I am logged in as a user with the "developer" role
    # Turning the auto-complete field into a select list doesn't work like on my local...
  And I go to "admin/structure/field-collections/field-block-option/fields/field_block/widget-type"
  And I select "Select list" from "Widget type"
  And I press "Continue"
  Then I should see "Changed the widget for field Block."
  Then I go to "block/add/a-b-block"
  And I fill in "Label" with "A/B Block"
    # And I select "Text Block A (Text Block A)" from "field_block_option[und][0][field_block][und]"
  And I select "Text Block A (Text Block A)" from "edit-field-block-option-und-0-field-block-und"
  And I fill in "edit-field-block-option-und-0-field-percentage-und-0-value" with "100"
  And I press "Add another item"
  And I wait for the ".ajax-new-content" element to appear
  And I select "Text Block B (Text Block B)" from "field_block_option[und][1][field_block][und]"
  And I fill in "edit-field-block-option-und-1-field-percentage-und-0-value" with "0"
  When I press "Save"
  Then I should see "A/B Block"
  And I should see "Text Block A Content AAA"
  When I follow "Edit Block"
  And I wait for the "#field-block-option-values" element to appear
  And I select "Text Block B (Text Block B)" from "field_block_option[und][0][field_block][und]"
  And I select "Text Block A (Text Block A)" from "field_block_option[und][1][field_block][und]"
  And I press "Save"
  Then I should see "A/B Block"
  And I should see "Text Block B Content BBB"
