@video_hero_unit
Feature: Video Hero Unit Block
When I login to a Web Express website
As an authenticated user with the right permission
I should be able to create a Video Hero Unit block

Scenario Outline: An authenticated user should be able to access the form for a Video Hero Unit block
  Given  I am logged in as a user with the <role> role
  When I go to "block/add/video-hero-unit"
  Then I should see <message>

  Examples:
  | role            | message                        |
  | edit_my_content | "Access Denied"                |
  | edit_only       | "Access Denied"                |
  | site_owner      | "Create Video Hero Unit block" |
  | administrator   | "Create Video Hero Unit block" |
  | developer       | "Create Video Hero Unit block" |

Scenario: An anonymous user should not be able to access the form for adding a Video Hero Unit block
  When I am on "block/add/video-hero-unit"
  Then I should see "Access denied"

# THE VIDEO HERO UNIT OFFERS SEVERAL DISPLAY OPTIONS
Scenario: Block Functionality - A video hero unit offers several display options
  Given I am logged in as a user with the "site_owner" role
  And I am on "block/add/video-hero-unit"
  Then I should see a "#edit-field-hero-video-overlay-und" element
  Then I should see a "#edit-field-hero-unit-text-color-und" element
  And I should see a "#edit-field-hero-unit-link-color-und" element
  And I should see a "#edit-field-hero-unit-text-align-und" element
  And I should see a "#edit-field-hero-video-size-und" element

# TEST THAT A VIDEO HERO UNIT BLOCK CAN BE CREATED AND REVISED
Scenario: Block Functionality - A very simple Video Hero Unit can be created
  Given I am logged in as a user with the "site_owner" role
  And I am on "block/add/video-hero-unit"
  And fill in "edit-label" with "My Video Hero Unit Label"
  And fill in "edit-title" with "My Video Hero Unit Title"
  And I fill in "edit-field-hero-unit-headline-und-0-value" with "Important Headline"
  And I fill in "edit-field-video-hero-url-und-0-value" with "347806953"
  And I attach the file "ralphieMtns.jpg" to "edit-field-hero-unit-image-und-0-upload"
  When I press "edit-submit"
  Then I should see "Video Hero Unit My Video Hero Unit Title has been created"
