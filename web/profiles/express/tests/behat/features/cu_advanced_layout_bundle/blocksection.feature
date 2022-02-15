@AdvLayoutBundle @block-section-block
Feature: the Block Section Block
In order to place a block on a background graphic
As a user with the proper role
I should be able to access and use the Block Section Block


Scenario Outline: An authenticated user should be able to access the form for adding a block section block
    Given I am logged in as a user with the <role> role
    When I go to "block/add/block-section"
    Then I should see <message>

    Examples:
    | role            | message         |
    | edit_my_content | "Access denied" |
    | edit_only       | "Access denied" |
    | site_owner      | "Create Block Section block" |
    | administrator   | "Create Block Section block" |
    | developer       | "Create Block Section block" |


Scenario: An anonymous user should not be able to access the form
  Given I go to "block/add/block-section"
  Then I should see "Access denied"


Scenario: Background Effects, Background Colors, Text Colors and Content Background choices
Given  I am logged in as a user with the "site_owner" role
And am on "block/add/block-section"
# BACKGROUND EFFECTS
When I select "Fixed" from "edit-field-block-section-bg-effect-und"
When I select "Scroll" from "edit-field-block-section-bg-effect-und"
When I select "Parallax" from "edit-field-block-section-bg-effect-und"
# BACKGROUND COLOR CHOICES
When I select "White" from "edit-field-hero-unit-bg-color-und"
When I select "Gray" from "edit-field-hero-unit-bg-color-und"
When I select "Black" from "edit-field-hero-unit-bg-color-und"
When I select "Dark Gray" from "edit-field-hero-unit-bg-color-und"
When I select "Gold" from "edit-field-hero-unit-bg-color-und"
When I select "Tan" from "edit-field-hero-unit-bg-color-und"
When I select "Light Blue" from "edit-field-hero-unit-bg-color-und"
# TEXT COLOR CHOICES
When I select "Black" from "edit-field-hero-unit-text-color-und"
When I select "White" from "edit-field-hero-unit-text-color-und"
# CONTENT BACKGROUND CHOICES
When I select "Hidden" from "edit-field-block-section-content-bg-und"
When I select "Transparent" from "edit-field-block-section-content-bg-und"
And I select "Solid" from "edit-field-block-section-content-bg-und"

@javascript
#Note: You can't create a Block Section Block w/o javascript
Scenario: A Block Section Block can be created
Given I am logged in as a user with the "site_owner" role
And I go to "block/add/block-section"
And I fill in "edit-label" with "My Block Section Block Label"
And I fill in "edit-title" with "My Block Section Block Title"
# CREATE a TEXT BLOCK
And I select "Text Block" from "edit-field-blocks-section-blocks-und-actions-bundle"
And I wait for the ".ief-form" element to appear
And I fill in "edit-field-blocks-section-blocks-und-form-label" with "Ralphie Buffalo Label"
And I fill in "edit-field-blocks-section-blocks-und-form-title" with "Ralphie Buffalo Title"
And I follow "Disable rich-text"
 And I fill in "Body" with "Ralphie Handlers run Ralphie around Folsom Field."
 And I press "Create block"
# JAVASCRIPT CANNOT FIND GRAPHIC And I attach the file "ralphieMtns.jpg" to "edit-field-block-section-bg-image-und-0-upload"
# And I press "edit-field-block-section-bg-image-und-0-upload-button"
And I press "Save"
Then the response should contain "My Block Section Block Title"
Then the response should contain "Ralphie Buffalo Title"
Then the response should contain "Ralphie Handlers run Ralphie around Folsom Field"

@javascript
# This test depends on the one above to create its content
Scenario: An EditOnly can edit but not delete a Block Section Block
  Given I am logged in as a user with the "edit_only" role
  And am on "block/my-block-section-block-label/edit"
  Then I should not see "Access denied"
  And the response should not contain "id=\"edit-delete\""
