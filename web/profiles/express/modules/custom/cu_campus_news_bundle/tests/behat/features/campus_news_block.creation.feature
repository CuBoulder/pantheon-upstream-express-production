@campus_news_block
Feature: Campus News Block

    When I login to a Web Express website
    As an authenticated user with the right permission
    I should be able to create a campus news block

    Scenario Outline: An authenticated user should be able to access the form for adding a campus news block
        Given  I am logged in as a user with the <role> role
        When I go to "block/add/campus-news"
        Then I should see <message>

        Examples:
            | role            | message                    |
            | edit_my_content | "Access Denied"            |
            | edit_only       | "Access Denied"            |
            | site_editor     | "Create Campus News block" |
            | site_owner      | "Create Campus News block" |
            | administrator   | "Create Campus News block" |
            | developer       | "Create Campus News block" |

    Scenario: An anonymous user should not be able to access the form for adding a campus news block
        When I am on "node/add/campus-news"
        Then I should see "Access denied"
