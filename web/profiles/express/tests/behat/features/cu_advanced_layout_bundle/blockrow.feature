@AdvLayoutBundle  @block-row-block
Feature: the Block Row Block
  In order to placed blocks side by side
  As a user with the proper role
  I should be able to access and use the Block Row Block


Scenario Outline: An authenticated user should be able to access the form for adding a block row block
  Given I am logged in as a user with the <role> role
  When I go to "block/add/block-row"
  Then I should see <message>

  Examples:
    | role            | message         |
    | edit_my_content | "Access denied" |
    | edit_only       | "Access denied" |
    | site_owner      | "Create Block Row block" |
    | administrator   | "Create Block Row block" |
    | developer       | "Create Block Row block" |


Scenario: An anonymous user should not be able to access the form
  Given I go to "block/add/block-row"
  Then I should see "Access denied"

@javascript
#Note: You can't create a Block Row Block w/o javascript
Scenario: A Block Row Block can be created
  Given I am logged in as a user with the "site_owner" role
    And I go to "block/add/block-row"
    And I fill in "edit-label" with "My Block Row Block Label"
    And I fill in "edit-title" with "My Block Row Block Title"
# Create first text block
  Then I select "Text Block" from "edit-field-block-row-collection-und-0-field-block-row-block-und-actions-bundle"
    And I wait for the ".ief-form" element to appear
    And I fill in "Text Block Label" with "BR Text One Label"
    And I fill in "Text Block Title" with "BR Text One Title"
    And I follow "Disable rich-text"
    And fill in "Body" with "Cupcake ipsum dolor sit amet ice cream carrot cake"
    And I press "Create block"
# Create second text block
  Then I press "Add another column"
    And I wait for the "#edit-field-block-row-collection-und-1-field-block-row-block" element to appear
    And I select "Text Block" from "edit-field-block-row-collection-und-1-field-block-row-block-und-actions-bundle"
    And I wait for the ".ief-form" element to appear
    And I fill in "Text Block Label" with "BR Text Two Label"
    And I fill in "Text Block Title" with "BR Text Two Title"
    And I follow "Disable rich-text"
    And fill in "Body" with "Lemon drops dessert chocolate gingerbread dessert"
    And I press "Create block"
    And I check "edit-field-block-row-match-height-und"
  When I press "Save"
    Then the response should contain "My Block Row Block Title"
    And the response should contain "Cupcake ipsum dolor sit amet ice cream carrot cake"
    And the response should contain "Lemon drops dessert chocolate gingerbread dessert"

@javascript
# This test depends on the one above
Scenario: An EditOnly can edit a Block Row but not delete it
  Given I am logged in as a user with the "edit_only" role
    And am on "block/my-block-row-block-label/edit"
  Then I should not see "Access denied"
    And the response should not contain "id=\"edit-delete\""
