@cu_campus_news_bundle
Feature: Campus News Block
When I login to a Web Express website
As an authenticated user with the right permission
I should be able to create a campus news block

Scenario Outline: An authenticated user should be able to access the form for adding a campus news block
    Given  I am logged in as a user with the <role> role
    When I go to "block/add/campus-news"
    Then I should see <message>

    Examples:
        | role            | message                         |
        | edit_my_content | "Access Denied"                 |
        | edit_only       | "Access Denied"                 |
        | site_editor     | "Create Campus News block" |
        | site_owner      | "Create Campus News block" |
        | administrator   | "Create Campus News block" |
        | developer       | "Create Campus News block" |

Scenario: An anonymous user should not be able to access the form for adding a campus news feature block
    When I am on "block/add/campus-news-feature"
    Then I should see "Access denied"

Scenario Outline: An authenticated user should be able to access the form for adding a campus news feature block
    Given  I am logged in as a user with the <role> role
    When I go to "block/add/campus-news-feature"
    Then I should see <message>

    Examples:
        | role            | message                         |
        | edit_my_content | "Access Denied"                 |
        | edit_only       | "Access Denied"                 |
        | site_editor     | "Create Campus News Feature block" |
        | site_owner      | "Create Campus News Feature block" |
        | administrator   | "Create Campus News Feature block" |
        | developer       | "Create Campus News Feature block" |

Scenario: An anonymous user should not be able to access the form for adding a campus news feature block
   When I am on "block/add/campus-news-feature"
   Then I should see "Access denied"

Scenario: Campus News Blocks and Campus Feature News Blocks contain type selection choices 
    Given I am logged in as a user with the "site_owner" role
    And I go to "block/add/campus-news"
    Then I should see "Unit"
    And I should see "Audience"
    And I should see "Category"
    And I go to "block/add/campus-news-feature"
    Then I should see "Unit"
    And I should see "Audience"
    And I should see "Category"
